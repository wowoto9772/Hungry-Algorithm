#include <stdio.h>

#include <vector>

using namespace std;

class Segment { // interval update (lgN) with lazy propagation

				// (lgN)*(lgN)
public:

	int S;
	vector <int> c, my, lz;

	int added;

	Segment(const vector<int> &y, int added_) {
		S = y.size();
		c.resize(S * 2);
		my.resize(S * 2);
		lz.resize(S * 2); // lazy propagation
		added = added_;
		init(y, 1, 0, S - 1);
	}

	void init(const vector <int> &y, int x, int xl, int xr) {
		if (xl < xr) {
			int m = (xl + xr) / 2;
			init(y, x << 1, xl, m);
			init(y, (x << 1) | 1, m + 1, xr);
			my[x] = my[x << 1] ^ my[(x << 1) | 1];
			c[x] = c[x << 1] + c[(x << 1) | 1];
		}
		else {
			my[x] = y[xl];
			if (xl >= S - added) {
				c[x] = 0;
			}
			else {
				c[x] = 1;
			}
		}
	}

	void update(int il, int ir, int v, int x, int xl, int xr) {

		if (il > xr || ir < xl)return;

		if (il <= xl && xr <= ir) {

			lz[x] ^= v;

		}
		else {
			int m = (xl + xr) / 2;

			lz[x << 1] ^= lz[x];
			lz[(x << 1) | 1] ^= lz[x];
			lz[x] = 0;

			update(il, ir, v, x << 1, xl, m);
			update(il, ir, v, (x << 1) | 1, m + 1, xr);

			int le = my[x << 1];
			if (c[x << 1] % 2)le ^= lz[x << 1];

			int ri = my[(x << 1) | 1];
			if (c[(x << 1) | 1] % 2)ri ^= lz[(x << 1) | 1];

			my[x] = le ^ ri;
		}

	}

	void update(int il, int ir, int v) {
		update(il, ir, v, 1, 0, S - 1);
	}

	int query(int il, int ir, int x, int xl, int xr) {

		if (il > xr || ir < xl) return 0;

		if (il <= xl && xr <= ir) {
			if (c[x] % 2 == 1) return my[x] ^ lz[x];
			return my[x];
		}
		else {

			lz[x << 1] ^= lz[x];
			lz[(x << 1) | 1] ^= lz[x];
			lz[x] = 0;

			int m = (xl + xr) / 2;

			int out = ((query(il, ir, x << 1, xl, m)) ^ (query(il, ir, (x << 1) | 1, m + 1, xr)));

			int le = my[x << 1];
			if (c[x << 1] % 2)le ^= lz[x << 1];

			int ri = my[(x << 1) | 1];
			if (c[(x << 1) | 1] % 2)ri ^= lz[(x << 1) | 1];

			my[x] = le ^ ri;

			return out;
		}
	}

	int query(int il, int ir) {
		return query(il, ir, 1, 0, S - 1);
	}

};

int main() {

	int n;
	scanf("%d", &n);

	vector <int> x(n);


	int k = 1;
	while (k < n)k <<= 1;

	for (int i = 0; i < n; i++)scanf("%d", &x[i]);

	int added = k - n;

	for (int i = 1; i <= k - n; i++)x.push_back(0);

	Segment tree(x, added);

	int q;
	scanf("%d", &q);

	while (q--) {

		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);

		if (a > b) {
			swap(a, b);
		}

		if (t == 2)printf("%d\n", tree.query(a, b));
		else {

			int v;
			scanf("%d", &v);

			tree.update(a, b, v);
		}

	}

}