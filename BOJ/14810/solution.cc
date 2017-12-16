#include <stdio.h>

template <class T>
class Vector {
public:

	T* arr;
	T* tarr;
	int _cap, _size;

	Vector() { arr = new T[2]; _cap = 2; _size = 0; }
	Vector(int n) {
		arr = new T[n];
		_cap = _size = n;
	}
	Vector(int n, T v) {

		arr = new T[n];
		_cap = _size = n;
		for (int i = 0; i < n; i++)arr[i] = v;
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

	T& operator[](int i) { return arr[i]; }

	void resize(int n) {
		arr = new T[n];
		_cap = _size = n;
	}

	void resize(int n, T v) {
		arr = new T[n];
		_cap = _size = n;
		for (int i = 0; i < n; i++)arr[i] = v;
	}

	int size() { return _size; }

	T back_left() {
		return arr[_size - 2];
	}

	T back() {
		return arr[_size - 1];
	}

	void pop_back() { _size--; }

	void push_back(T x) {
		if (_size == _cap) {
			T* tmp = new T[_cap * 2];
			for (int i = 0; i < _size; i++)tmp[i] = arr[i];
			_cap *= 2;
			delete[] arr;
			arr = tmp;
		}
		arr[_size++] = x;
	}

	bool empty() {
		return !(_size);
	}

	void clear() { _cap = 4; _size = 0; delete[] arr; arr = new T[4]; }
	~Vector() { delete[] arr, tarr; }

	void StableSort(int l, int r) {
		tarr = new T[_size];
		Divide(l, r);
	}


private:
	void Merge(int l, int mid, int r) {
		int ind = l;
		int pl = l, pr = mid + 1;
		while (pl <= mid && pr <= r) {
			if (arr[pr] < arr[pl]) {
				tarr[ind] = arr[pr];
				pr++, ind++;
			}
			else {
				tarr[ind] = arr[pl];
				pl++, ind++;
			}
		}

		if (pr == r + 1) {
			for (int i = pl; i <= mid; i++)tarr[ind++] = arr[i];
		}
		else { // pl = mid
			for (int i = pr; i <= r; i++)tarr[ind++] = arr[i];
		}

		// Conquer
		for (int i = l; i <= r; i++) {
			arr[i] = tarr[i];
		}
	}

	void Divide(int l, int r) {
		if (l < r) {
			int m = (l + r) / 2;
			Divide(l, m);
			Divide(m + 1, r);
			Merge(l, m, r);
		}
	}

};

class ele {
public:
	double r, s;
	bool operator<(const ele &A)const {
		if (r == A.r)return s > A.s;
		return r > A.r;
	}
};

Vector <ele> e(1000);

const double pi = 3.1415926535897932384626433832795; // acos(-1.0)

double dp[1003][1003];
int n, k;

double max(double a, double b) {
	if (a < b)a = b;
	return a;
}

double dy(int i, int j) {
	if (i == n - 1) {
		if (j == k)return 0.0;
		else
			return -100000000000000000;
	}
	if (dp[i][j] > -1000000000000000000)return dp[i][j];
	if (j + 1 <= k)dp[i][j] = dy(i + 1, j + 1) + e[i + 1].s;
	dp[i][j] = max(dp[i][j], dy(i + 1, j));
	return dp[i][j];
}

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &e[i].r, &e[i].s);
			e[i].s *= e[i].r * 2 * pi;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1000000000000000000;
			}
		}

		e.StableSort(0, n - 1);
		double ans = 0;
		for (int i = 0; i <= n - k; i++) {
			ans = max(ans, dy(i, 1) + e[i].r * e[i].r * pi + e[i].s);
		}

		printf("Case #%d: ", ++tc);
		printf("%.9lf\n", ans);
	}

}
