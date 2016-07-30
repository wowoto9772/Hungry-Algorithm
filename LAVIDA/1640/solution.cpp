//#include <stdio.h>
//#include <limits.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//#define ll long long
//#define min(a, b) a < b ? a : b
//#define max(a, b) a < b ? b : a
//
//class Segment{
//public:
//	vector <ll> t;
//	int S;
//	Segment(const int &n){
//		S = n;
//		t.resize(n * 4);
//	}
//	void update(int il, int ir, int v, int x, int xl, int xr){
//		// [il, ir) + x
//		// k : [xl, xr)
//		if (il <= xl && xr <= ir){
//			t[x] += v;
//		}
//		else if (xl < ir && il < xr){
//			t[x] += (min(ir, xr) - max(il, xl)) * v;
//			int m = (xl + xr) / 2;
//			update(il, ir, v, x * 2, xl, m);
//			update(il, ir, v, x * 2 + 1, m, xr);
//		}
//	}
//
//	ll sum(int il, int ir, int x, int xl, int xr){
//		if (ir <= xl || xr <= il)return 0;
//		else if (il <= xl && xr <= ir){
//			return t[x] * (xr - xl) + t[x];
//		}
//		else{
//			ll ret = (min(ir, xr) - max(il, xl)) * t[x];
//			int m = (xl + xr) / 2;
//			ret += sum(il, ir, x * 2, xl, m);
//			ret += sum(il, ir, x * 2 + 1, m, xr);
//			return ret;
//		}
//	}
//
//};
//
//class ele{
//public:
//	int a, b, c;
//	bool operator<(const ele &A)const{
//		if (a == A.a)return b < A.b;
//		return a < A.a;
//	}
//}I[40002];
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		vector <int> x;
//
//		for (int i = 1; i <= n; i++){
//			scanf("%d %d %d", &I[i].a, &I[i].b, &I[i].c);
//			x.push_back(I[i].a);
//			x.push_back(I[i].b);
//		}
//
//		sort(I + 1, I + 1 + n);
//		sort(x.begin(), x.end());
//		x.resize(distance(x.begin(), unique(x.begin(), x.end())));
//
//		Segment tree(n);
//
//		for (int i = 1; i <= n; i++){
//			int l = 0, r = x.size() - 1, m;
//			while (l <= r){
//				m = (l + r) / 2;
//				if (x[m] < I[i].a){
//					l = m + 1;
//				}
//				else if (x[m] > I[i].a){
//					r = m - 1;
//				}
//				else{
//					break;
//				}
//			}
//			int il = m;
//			l = 0, r = x.size() - 1;
//			while (l <= r){
//				m = (l + r) / 2;
//				if (x[m] < I[i].b){
//					l = m + 1;
//				}
//				else if (x[m] > I[i].b){
//					r = m - 1;
//				}
//				else{
//					break;
//				}
//			}
//			int ir = m;
//			tree.update(il, ir+1, I[i].c, 1, 0, x.size()-1);
//			printf("%lld\n", tree.sum(il, ir+1, 1, 0, x.size() - 1));
//		}
//	}
//}

//#include <stdio.h>
//#include <limits.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//#define ll long long
//#define min(a, b) a < b ? a : b
//#define max(a, b) a < b ? b : a
//
//class Segment{
//public:
//	vector <ll> t;
//	vector <int> c;
//	int S;
//	Segment(const int &n){
//		S = n;
//		t.resize(n * 4);
//		c.resize(n * 4);
//	}
//	void update(int il, int ir, int v, int x, int xl, int xr){
//		// [il, ir) + x
//		// k : [xl, xr)
//		if (il <= xl && xr <= ir){
//			c[x] += v;
//		}
//		else if (xl < ir && il < xr){
//			int m = (xl + xr) / 2;
//			update(il, ir, v, x * 2, xl, m);
//			update(il, ir, v, x * 2 + 1, m, xr);
//			t[x] = 0;
//			if (c[x] > 0)t[x] = xr - xl + 1;
//			if (c[x] == 0 && xl < xr)t[x] = t[x * 2] + t[x * 2 + 1];
//		}
//	}
//
//	/*
//	ll sum(int il, int ir, int x, int xl, int xr){
//		if (ir <= xl || xr <= il)return 0;
//		else if (il <= xl && xr <= ir){
//			return t[x] * (xr - xl) + t[x];
//		}
//		else{
//			ll ret = (min(ir, xr) - max(il, xl)) * t[x];
//			int m = (xl + xr) / 2;
//			ret += sum(il, ir, x * 2, xl, m);
//			ret += sum(il, ir, x * 2 + 1, m, xr);
//			return ret;
//		}
//	} */
//
//};
//
//class ele{
//public:
//	int a, b, c;
//	bool operator<(const ele &A)const{
//		if (a == A.a)return b < A.b;
//		return a < A.a;
//	}
//}I[40002];
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		vector <int> x;
//
//		for (int i = 1; i <= n; i++){
//			scanf("%d %d %d", &I[i].a, &I[i].b, &I[i].c);
//			x.push_back(I[i].a);
//			x.push_back(I[i].b);
//		}
//
//		sort(I + 1, I + 1 + n);
//		sort(x.begin(), x.end());
//		x.resize(distance(x.begin(), unique(x.begin(), x.end())));
//
//		Segment tree(n);
//		for (int i = 1; i <= n; i++){
//			int l = 0, r = x.size() - 1, m;
//			while (l <= r){
//				m = (l + r) / 2;
//				if (x[m] < I[i].a){
//					l = m + 1;
//				}
//				else if (x[m] > I[i].a){
//					r = m - 1;
//				}
//				else{
//					break;
//				}
//			}
//			int il = m;
//			l = 0, r = x.size() - 1;
//			while (l <= r){
//				m = (l + r) / 2;
//				if (x[m] < I[i].b){
//					l = m + 1;
//				}
//				else if (x[m] > I[i].b){
//					r = m - 1;
//				}
//				else{
//					break;
//				}
//			}
//			int ir = m;
//		}
//	}
//}

//#include <stdio.h>
//#include <limits.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//#define ll long long
//
//class rect{
//public:
//	ll x, y, y2;
//	int f;
//	bool operator<(const rect &X)const{
//		if (x == X.x){
//			if (y == X.y)return f > X.f;
//			return y < X.y;
//		}
//		return x < X.x;
//	}
//}I[40003];
//
//class Segment{
//public:
//	int S;
//	vector <ll> t;
//	vector <int> c;
//	vector <int> y;
//
//	Segment(const int &n, const vector <int> &Y){
//		S = n;
//		t.resize(S * 4 + 1);
//		c.resize(S * 4 + 1);
//		y = Y; 
//	}
//
//	void update(int il, int ir, int v, int x, int xl, int xr){
//		if (il > xr || ir < xl)return;
//		if (il <= xl && xr <= ir)c[x] += v;
//		else{
//			int m = (xl + xr) / 2;
//			update(il, ir, v, x * 2, xl, m);
//			update(il, ir, v, x * 2 + 1, m + 1, xr);
//		}
//		t[x] = 0;
//		if (c[x] > 0)t[x] = (y[xr] - y[xl-1] - 1) + 1;
//		if (!c[x] && xl < xr)t[x] = t[x * 2] + t[x * 2 + 1];
//	}
//
//	ll sum(){
//		return t[1];
//	}
//};
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		int top = 0;
//
//		vector <int> y;
//
//		y.push_back(0);
//		for (int i = 1; i <= n; i++){
//			int a, b, c;
//			scanf("%d %d %d", &a, &b, &c);
//			I[top].x = a, I[top].y = 1, I[top].y2 = c, I[top].f = 1;
//			top++;
//			I[top].x = b, I[top].y = 1, I[top].y2 = c, I[top].f = -1;
//			top++;
//			y.push_back(c);
//		}
//
//		sort(y.begin(), y.end());
//		y.resize(distance(y.begin(), unique(y.begin(), y.end()))); 
//		
//		sort(I, I + top);
//
//		Segment tree(n, y);
//
//		int p = I[0].x;
//		ll ans = 0;
//		for (int i = 0; i < top; i++){
//			ans += (I[i].x - p) * tree.sum();
//			int l = 0, r = y.size() - 1, m;
//			while (l <= r){
//				m = (l + r) / 2;
//				if (y[m] < I[i].y2)l = m + 1;
//				else if (y[m] > I[i].y2)r = m - 1;
//				else
//					break; 
//			}
//			tree.update(1, m, I[i].f, 1, 1, y.size()-1);
//			p = I[i].x;
//		}
//
//		printf("%lld\n", ans);
//	}
//}

//#include <stdio.h>
//#include <limits.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//#define ll long long
//
//class rect{
//public:
//	ll x, y, y2;
//	int f;
//	bool operator<(const rect &X)const{
//		if (x == X.x){
//			if (y == X.y)return f < X.f;
//			return y < X.y;
//		}
//		return x < X.x;
//	}
//}I[80003];
//
//class Segment{
//public:
//	int S;
//	vector <ll> t;
//	vector <int> c;
//	vector <int> y;
//
//	Segment(const int &n, const vector <int> &Y){
//		S = n;
//		t.resize(S*2);
//		c.resize(S*2);
//		y = Y;
//	}
//
//	void update(int il, int ir, int v, int x, int xl, int xr){
//		if (il > xr || ir < xl)return;
//		if (il <= xl && xr <= ir)c[x] += v;
//		else{
//			int m = (xl + xr) / 2;
//			update(il, ir, v, x * 2, xl, m);
//			update(il, ir, v, x * 2 + 1, m + 1, xr);
//		}
//		t[x] = 0;
//		if (c[x] > 0){
//			t[x] = y[xr] - y[xl];
//		}
//		if (!c[x] && xl < xr)t[x] = t[x * 2] + t[x * 2 + 1];
//	}
//
//	ll sum(){
//		return t[1];
//	}
//};
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		int top = 0;
//
//		vector <int> y;
//
//		for (int i = 1; i <= n; i++){
//			int a, b, c;
//			scanf("%d %d %d", &a, &b, &c);
//			I[top].x = a, I[top].y = 0, I[top].y2 = c, I[top].f = 1;
//			top++;
//			I[top].x = b, I[top].y = 0, I[top].y2 = c, I[top].f = -1;
//			top++;
//			y.push_back(c);
//		}
//
//		sort(y.begin(), y.end());
//		y.resize(distance(y.begin(), unique(y.begin(), y.end())));
//		y.push_back(0);
//		int a = y.size();
//		for (int i = 0; i < a; i++)y.push_back(y[i]);
//		ll x = 1;
//		y.push_back(-1); // trash
//		a = y.size();
//		while (x < a)x <<= 1LL;
//		sort(y.begin(), y.end());
//		for (ll i = 1; i <= x - a; i++)y.push_back(INT_MAX);
//		sort(I, I + top);
//
//		Segment tree(y.size(), y);
//
//		int p = I[0].x;
//		ll ans = 0;
//		for (int i = 0; i < top; i++){
//			ans += (I[i].x - p) * tree.sum();
//			int l = 0, r = y.size() - 1, m, m2;
//			while (l <= r){ // lower_bound
//				m = (l + r) / 2;
//				if (y[m] < I[i].y)l = m + 1;
//				else if (y[m] > I[i].y)r = m - 1;
//				else{
//					r = m - 1;
//				}
//			}
//			if (y[m] != I[i].y)m++;
//			l = 0, r = y.size() - 1;
//			while (l <= r){ // upper_bound
//				m2 = (l + r) / 2;
//				if (y[m2] < I[i].y2)l = m2 + 1;
//				else if (y[m2] > I[i].y2)r = m2 - 1;
//				else{
//					l = m2 + 1;
//				}
//			}
//			if (y[m2] != I[i].y2)m2--;
//			tree.update(m, m2, I[i].f, 1, 0, y.size() - 1);
//			p = I[i].x;
//		}
//
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

class rect{
public:
	ll x, y, y2;
	int f;
	bool operator<(const rect &X)const{
		if (x == X.x){
			if (y == X.y)return f < X.f;
			return y < X.y;
		}
		return x < X.x;
	}
}I[80003];

class Segment{
public:
	int S;
	vector <ll> t;
	vector <int> c;
	vector <int> y;

	Segment(const int &n, const vector <int> &Y){
		S = n;
		t.resize(S * 2);
		c.resize(S * 2);
		y = Y;
	}

	void update(int il, int ir, int v, int x, int xl, int xr){
		if (il > xr || ir < xl)return;
		if (il <= xl && xr <= ir)c[x] += v;
		else{
			int m = (xl + xr) / 2;
			update(il, ir, v, x * 2, xl, m);
			update(il, ir, v, x * 2 + 1, m + 1, xr);
		}
		t[x] = 0;
		if (c[x] > 0){
			t[x] = y[xr] - y[xl];
		}
		if (!c[x] && xl < xr)t[x] = t[x * 2] + t[x * 2 + 1];
	}

	ll sum(){
		return t[1];
	}
};

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int top = 0;

		vector <int> y, x;

		for (int i = 1; i <= n; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			I[top].x = a, I[top].y = 0, I[top].y2 = c, I[top].f = 1;
			top++;
			I[top].x = b, I[top].y = 0, I[top].y2 = c, I[top].f = -1;
			top++;
		}

		sort(I, I + top);
		x.resize(distance(x.begin(), unique(x.begin(), x.end())));
		
		ll ans = 0;
		printf("%lld\n", ans);
	}
}