#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

class rect {
public:
	ll x, y, y2;
	int f;
	bool operator<(const rect &X)const {
		if (x == X.x) {
			if (y == X.y)return f < X.f;
			return y < X.y;
		}
		return x < X.x;
	}
}I[40003];

class Segment {
public:
	int S;
	vector <ll> t;
	vector <int> c;
	vector <int> y;

	Segment(const int &n, const vector <int> &Y) {
		S = n;
		t.resize(S * 4);
		c.resize(S * 4);
		y = Y;
	}

	void update(int il, int ir, int v, int x, int xl, int xr) {
		if (il > xr || ir < xl)return;
		if (il <= xl && xr <= ir)c[x] += v;
		else {
			int m = (xl + xr) / 2;
			update(il, ir, v, x * 2, xl, m);
			update(il, ir, v, x * 2 + 1, m + 1, xr);
		}
		t[x] = 0;
		if (c[x] > 0) {
			t[x] = y[xr] - y[xl];
		}
		if (!c[x] && xl < xr)t[x] = t[x * 2] + t[x * 2 + 1];
	}

	ll sum() {
		return t[1];
	}
};

int main()
{
	int n;
	scanf("%d", &n);

	int top = 0;

	vector <int> y;

	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		I[top].x = a, I[top].y = b, I[top].y2 = d, I[top].f = 1;
		top++;
		I[top].x = c, I[top].y = b, I[top].y2 = d, I[top].f = -1;
		top++;
		y.push_back(b);
		y.push_back(d);
	}

	sort(y.begin(), y.end());
	y.resize(distance(y.begin(), unique(y.begin(), y.end())));
	int a = y.size();
	for (int i = 0; i < a; i++)y.push_back(y[i]);
	ll x = 1;
	y.push_back(-1);
	a = y.size();
	while (x < a)x <<= 1;
	for (ll i = 1; i <= x - a; i++)y.push_back(INT_MAX);

	sort(y.begin(), y.end());
	sort(I, I + top);

	Segment tree(y.size(), y);

	int p = I[0].x;
	ll ans = 0;
	for (int i = 0; i < top; i++) {
		ans += (I[i].x - p) * tree.sum();
		int l = 0, r = y.size() - 1, m, m2;
		while (l <= r) { // lower_bound
			m = (l + r) / 2;
			if (y[m] < I[i].y)l = m + 1;
			else if (y[m] > I[i].y)r = m - 1;
			else {
				r = m - 1;
			}
		}
		if (y[m] != I[i].y)m++;
		l = 0, r = y.size() - 1;
		while (l <= r) { // upper_bound
			m2 = (l + r) / 2;
			if (y[m2] < I[i].y2)l = m2 + 1;
			else if (y[m2] > I[i].y2)r = m2 - 1;
			else {
				l = m2 + 1;
			}
		}
		if (y[m2] != I[i].y2)m2--;

		tree.update(m, m2, I[i].f, 1, 0, y.size() - 1);
		p = I[i].x;
	}

	printf("%lld\n", ans);
}