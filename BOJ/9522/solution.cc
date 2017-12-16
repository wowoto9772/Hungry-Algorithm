#include <stdio.h>

int max(int a, int b) {
	if (a < b)a = b;
	return a;
}

template <class T> void StableSort(T *buf, T *begin, T *end) {
	if (end - begin >= 2) {
		int m = ((end - begin) >> 1);

		// divide
		StableSort(buf, begin, begin + m);
		StableSort(buf, begin + m, end);

		T *buf = new T[end - begin];

		int pl = 0, pr = m;
		int plend = m, prend = end - begin;
		int top = 0;

		while (pl < plend && pr < prend) {
			if (*(begin + pl) < *(begin + pr)) {
				buf[top++] = *(begin + pl);
				pl++;
			}
			else {
				buf[top++] = *(begin + pr);
				pr++;
			}
		}

		if (pr == prend) {
			for (int i = pl; i < plend; i++)buf[top++] = *(begin + i);
		}
		else { // pl = plend
			for (int i = pr; i < prend; i++)buf[top++] = *(begin + i);
		}

		// conquer
		for (int i = 0; i < prend; i++) {
			*begin = buf[i];
			begin++;
		}
	}
}

template <class T> T* Unique(T *begin, T *end) { // [begin:end)
	if (begin == end)return end;
	T *ret = begin;
	while (++begin != end) {
		if (!(*ret == *begin))*(++ret) = *begin;
	}return ++ret;
}

template <class T> void StableSort(T *begin, T *end) { // [begin:end)
	T *buf = new T[end - begin];
	StableSort(buf, begin, end);
	delete[]buf;
}

template <class T>
class Vector {

	T* arr;
	int _cap, _size;

public:

	Vector() { arr = new T[2]; _cap = 2; _size = 0; }

	Vector(int n) {
		arr = new T[n];
		_cap = _size = n;
	}

	Vector(int n, T init) {
		arr = new T[n];
		_cap = _size = n;
		for (int i = 0; i < n; i++)arr[i] = init;
	}

	Vector(const Vector <T> & you) {
		_size = you._size;
		_cap = you._cap;
		arr = new T[_cap];
		for (int i = 0; i < _size; i++)arr[i] = you.arr[i];
	}

	Vector<T>& operator = (const Vector<T>& you) {
		delete[] arr;
		_cap = you._cap, _size = you._size;
		arr = new T[_cap];
		for (int i = 0; i < _size; i++)arr[i] = you.arr[i];
		return *this;
	}

	T* begin() { return arr; }
	T* end() { return arr + _size; }

	T& operator[](int i) { return arr[i]; }

	int min(int a, int b) {
		if (a > b)a = b;
		return a;
	}

	void resize(int n) {
		T* buf = new T[n];
		for (int i = 0; i < min(_cap, n); i++)buf[i] = arr[i];
		delete[] arr;
		arr = buf;
		_cap = _size = n;
	}

	void resize(int n, T init) {
		delete[] arr;
		arr = new T[n];
		_cap = _size = n;
		for (int i = 0; i < n; i++)arr[i] = init;
	}

	int size() { return _size; }

	T back() {
		return arr[_size - 1];
	}

	void pop_back() { _size--; }

	void push_back(T newElement) {
		if (_size == _cap) {
			T* tmp = new T[_cap * 2];
			for (int i = 0; i < _size; i++)tmp[i] = arr[i];
			_cap *= 2;
			delete[] arr;
			arr = tmp;
		}
		arr[_size++] = newElement;
	}

	bool empty() {
		return !(_size);
	}

	void clear() { _cap = 2; _size = 0; delete[] arr; arr = new T[2]; }
	~Vector() { delete[] arr; }

};

// from https://github.com/kcm1700/algorithms
// in: n, m, graph
// out: match, matched
// vertex cover: (reached[0][left_node] == 0) || (reached[1][right_node] == 1)
struct BipartiteMatching
{
	// hopkroft karp algorithm (n sqrt n)
	int n, m;
	Vector<Vector<int> > graph;
	Vector<int> matched, match;
	Vector<int> edgeview;
	Vector<int> level;
	Vector<int> reached[2];
	BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1), match(n, -1) {}

	bool assignLevel()
	{
		bool reachable = false;
		level.resize(n, -1);
		reached[0].resize(n, 0);
		reached[1].resize(m, 0);

		int q[1003];
		int front = 0, tale = 0;
		for (int i = 0; i < n; i++) {
			if (match[i] == -1) {
				level[i] = 0;
				reached[0][i] = 1;
				q[tale++] = i;
			}
		}

		while (front < tale) {
			int cur = q[front++];
			for (int i = 0; i < graph[cur].size(); i++) {
				int adj = graph[cur][i];
				reached[1][adj] = 1;
				int next = matched[adj];
				if (next == -1) {
					reachable = true;
				}
				else if (level[next] == -1) {
					level[next] = level[cur] + 1;
					reached[0][next] = 1;
					q[tale++] = next;
				}
			}
		}
		return reachable;
	}

	int findpath(int nod) {
		for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
			int adj = graph[nod][i];
			int next = matched[adj];
			if (next >= 0 && level[next] != level[nod] + 1) continue;
			if (next == -1 || findpath(next)) {
				match[nod] = adj;
				matched[adj] = nod;
				return 1;
			}
		}
		return 0;
	}

	int solve()
	{
		int ans = 0;
		while (assignLevel()) {
			edgeview.resize(n, 0);
			for (int i = 0; i < n; i++)
				if (match[i] == -1)
					ans += findpath(i);
		}
		return ans;
	}
};

int main() {

	int n;
	scanf("%d", &n);

	BipartiteMatching btm(500, 500);

	Vector <int> u, v;

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		u.push_back(x);
		v.push_back(y);
		btm.graph[x].push_back(y);
	}

	StableSort(u.begin(), u.end());
	StableSort(v.begin(), v.end());

	u.resize(Unique(u.begin(), u.end()) - u.begin());
	v.resize(Unique(v.begin(), v.end()) - v.begin());

	int g = max(u.size(), v.size());

	if (btm.solve() != g)printf("Mirko");
	else
		printf("Slavko");

}