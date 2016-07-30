#include <stdio.h>
#include <limits.h>

#include <queue>

#include <algorithm>

#define ll long long

using namespace std;

class ele {
public:

	ll bx, by, tx, ty;

	bool operator<(const ele &A)const {

		return bx < A.bx;

	}

}e[100003];

class dat {
public:

	ll x, y;
	int k;

	dat() {}
	dat(ll x_, ll y_, int k_) {
		x = x_, y = y_, k = k_;
	}

	bool operator<(const dat &A)const {
		return x > A.x;
	}

};

class RMQ {
public:

	int n;
	vector <int> t;

	RMQ(int n_) {
		n = n_;
		t.resize(2 * n);
	}

	int query(int il, int ir, int x, int xl, int xr) {
		if (ir < xl || xr < il) {
			return 0;
		}
		else if (il <= xl && xr <= ir) {
			return t[x];
		}
		else {
			int m = (xl + xr) / 2;
			return max(query(il, ir, x << 1, xl, m), query(il, ir, (x << 1) | 1, m + 1, xr));
		}
	}

	int query(int il, int ir) {
		return query(il, ir, 1, 0, n - 1);
	}

	int update(int p, int v, int x, int xl, int xr) {
		if (p < xl || xr < p) {
			return t[x];
		}
		else if (xl == xr) {
			if (t[x] < v)t[x] = v;
			return t[x];
		}
		else {
			int m = (xl + xr) / 2;
			return t[x] = max(update(p, v, x << 1, xl, m), update(p, v, (x << 1 | 1), m + 1, xr));
		}
	}

	int update(int p, int v) {
		return update(p, v, 1, 0, n - 1);
	}
};

int search(ll v, const vector <ll> &y) {

	int l = 0, r = y.size() - 1, m;

	while (l <= r) {

		m = (l + r) / 2;

		if (y[m] < v)l = m + 1;
		else if (y[m] > v)r = m - 1;
		else
			break;

	}

	return m;

}

int main() {

	int n;
	scanf("%d", &n);

	vector <ll> y;

	for (int i = 0; i < n; i++) {

		scanf("%lld %lld %lld %lld", &e[i].bx, &e[i].by, &e[i].tx, &e[i].ty);

		y.push_back(e[i].by);
		y.push_back(e[i].ty);

	}

	sort(e, e + n);

	y.push_back(LLONG_MIN);
	sort(y.begin(), y.end());
	y.resize(unique(y.begin(), y.end()) - y.begin());

	int k = 1;
	int s = y.size();

	while (k < y.size())k <<= 1;

	for (int i = 1; i <= k - s; i++)y.push_back(LLONG_MAX);

	RMQ tree(y.size());

	priority_queue <dat> q;

	for (int i = 0; i < n; i++) {

		while (!q.empty() && q.top().x < e[i].bx) {

			dat c = q.top(); q.pop();

			int p = search(c.y, y);

			tree.update(p, c.k);

			// update
		}

		int p = search(e[i].by, y);

		int k = tree.query(0, p - 1);

		q.emplace(e[i].tx, e[i].ty, ++k);

	}

	while (!q.empty()) {

		dat c = q.top(); q.pop();

		int p = search(c.y, y);

		tree.update(p, c.k);

	}

	printf("%d\n", tree.query(0, y.size() - 1));

}


/*

5
1 1 2 2
3 3 4 4
5 5 9 9
6 6 7 7
8 8 9 9

*/