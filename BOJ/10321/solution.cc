#include <stdio.h>
#include <math.h>

template <class T>
class Vector{
public:

	T* arr;
	T* tarr;
	int _cap, _size;

	Vector(){ arr = new T[2]; _cap = 2; _size = 0; }
	Vector(int n){
		arr = new T[n];
		_cap = _size = n;
	}
	Vector(int n, T v){
		arr = new T[n];
		_cap = _size = n;
		for (int i = 0; i < n; i++)arr[i] = v;
	}

	Vector(const Vector <T> & you){
		_size = you._size;
		_cap = you._cap;
		arr = new T[_cap];
		for (int i = 0; i < _size; i++)arr[i] = you.arr[i];
	}

	Vector<T>& operator = (const Vector<T>& you){
		delete[] arr;
		_cap = you._cap, _size = you._size;
		arr = new T[_cap];
		for (int i = 0; i < _size; i++)arr[i] = you.arr[i];
		return *this;
	}

	T& operator[](int i){ return arr[i]; }

	void resize(int n){
		arr = new T[n];
		_cap = _size = n;
	}

	void resize(int n, T v){
		arr = new T[n];
		_cap = _size = n;
		for (int i = 0; i < n; i++)arr[i] = v;
	}

	int size(){ return _size; }

	T back_left(){
		return arr[_size - 2];
	}

	T back(){
		return arr[_size - 1];
	}

	void pop_back(){ _size--; }

	void push_back(T x){
		if (_size == _cap){
			T* tmp = new T[_cap * 2];
			for (int i = 0; i < _size; i++)tmp[i] = arr[i];
			_cap *= 2;
			delete[] arr;
			arr = tmp;
		}
		arr[_size++] = x;
	}

	bool empty(){
		return !(_size);
	}

	void clear(){ _cap = 4; _size = 0; delete[] arr; arr = new T[4]; }
	~Vector(){ delete[] arr, tarr; }

	void StableSort(int l, int r){
		tarr = new T[_size];
		Divide(l, r);
	}


private:
	void Merge(int l, int mid, int r){
		int ind = l;
		int pl = l, pr = mid + 1;
		while (pl <= mid && pr <= r){
			if (arr[pr] < arr[pl]){
				tarr[ind] = arr[pr];
				pr++, ind++;
			}
			else{
				tarr[ind] = arr[pl];
				pl++, ind++;
			}
		}

		if (pr == r + 1){
			for (int i = pl; i <= mid; i++)tarr[ind++] = arr[i];
		}
		else{ // pl = mid
			for (int i = pr; i <= r; i++)tarr[ind++] = arr[i];
		}

		// Conquer
		for (int i = l; i <= r; i++){
			arr[i] = tarr[i];
		}
	}

	void Divide(int l, int r){
		if (l < r){
			int m = (l + r) / 2;
			Divide(l, m);
			Divide(m + 1, r);
			Merge(l, m, r);
		}
	}

};

#define ll long long

class Point{
public:
	ll x, y;
	Point(){}
	Point(ll _x, ll _y){
		x = _x, y = _y;
	}
	bool operator<(const Point &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
};

int ccw(const Point &a, const Point &b, const Point &c) {
	ll dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;
	ll ret = dx1*dy2 - dx2*dy1;
	if (ret < 0)return -1;
	else if (ret > 0)return 1;
	else return 0;
}

int p, q;

Vector < Point > ConvexHull(Vector < Point > &point){

	point.StableSort(0, point.size() - 1);

	Vector < Point > up, down;
	for (int i = 0; i < point.size(); i++){
		while (up.size() >= 2 && ccw(up.back_left(), up.back(), point[i]) <= 0)up.pop_back();
		up.push_back(point[i]);
		while (down.size() >= 2 && ccw(down.back_left(), down.back(), point[i]) >= 0)down.pop_back();
		down.push_back(point[i]);
	}

	Vector < Point > ans = up;
	q = ans.size() - 1;
	for (int i = down.size() - 2; i >= 1; i--){
		ans.push_back(down[i]);
	}

	return ans;
}

ll max(ll a, ll b){
	if (a < b)a = b;
	return a;
}

double vectorSize(ll vx, ll vy){
	return sqrt((double)vx*vx + vy*vy);
}

ll distance(Point &a, Point &b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

ll calcArea(const Point &a, const Point &b, const Point &c) {
	ll dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;
	ll ret = dx1*dy2 - dx2*dy1;
	if (ret < 0)ret = -ret;
	return ret;
}

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--){

		int n;
		scanf("%d", &n);

		Vector < Point > point(n);

		for (int i = 0; i < n; i++)scanf("%lld %lld", &point[i].x, &point[i].y);

		p = 0;
		point = ConvexHull(point);

		n = point.size();

		ll ans = 0;

		ll vx[2] = { 0, 0 }, vy[2] = { -1, 1 };
		// parallel but counter direction
		ll nvx[2], nvy[2];
		double cos1, cos2;

		int a, b;

		for (int i = 0; i < n; i++){

			if (ans < distance(point[p], point[q])){
				a = p, b = q;
				ans = distance(point[p], point[q]);
			}

			nvx[0] = point[(p + 1) % n].x - point[p].x, nvy[0] = point[(p + 1) % n].y - point[p].y;
			nvx[1] = point[(q + 1) % n].x - point[q].x, nvy[1] = point[(q + 1) % n].y - point[q].y;

			cos1 = (vx[0] * nvx[0] + vy[0] * nvy[0]) / (vectorSize(vx[0], vy[0]) * vectorSize(nvx[0], nvy[0]));
			cos2 = (vx[1] * nvx[1] + vy[1] * nvy[1]) / (vectorSize(vx[1], vy[1]) * vectorSize(nvx[1], nvy[1]));

			if (cos1 > cos2){
				p = (p + 1) % n;
				vx[0] = nvx[0];
				vy[0] = nvy[0];
				vx[1] = -vx[0];
				vy[1] = -vy[0];
			}
			else{
				q = (q + 1) % n;
				vx[1] = nvx[1];
				vy[1] = nvy[1];
				vx[0] = -vx[1];
				vy[0] = -vy[1];
			}
		}

		ans = 0;

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				ans = max(ans, calcArea(point[i], point[j], point[a]) + calcArea(point[i], point[j], point[b]));
			}
		}

		printf("#%d %lld", ++tc, ans>>1);
		if (ans & 1)printf(".5");

		puts("");

	}

}

// edit