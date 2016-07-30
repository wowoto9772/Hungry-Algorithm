#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>

using namespace std;

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

class Segment {
public:
	// find interval's maximum consecutive length
	int n;

	class ele {
	public:

		int l, r;
		int le, ri, ans;
		int len;

		ele() {}
		ele(int l_, int r_, int le_, int ri_, int ans_, int len_) {
			l = l_, r = r_, le = le_, ri = ri_, ans = ans_, len = len_;
		}

	};

	vector <ele> t;

	Segment(const vector <int> &I) {
		n = I.size();
		t.resize(4 * n + 1);
		init(I, 1, 0, n - 1);
	}

	void init(const vector <int> &I, int x, int xl, int xr) {

		if (xl == xr) {
			t[x].le = t[x].ri = t[x].ans = t[x].l = t[x].r = t[x].len = I[xl];
		}
		else {

			int m = (xl + xr) / 2;

			init(I, lson(x), xl, m);
			init(I, rson(x), m + 1, xr);

			t[x].len = t[lson(x)].len + t[rson(x)].len;
			t[x].l = t[lson(x)].l, t[x].r = t[rson(x)].r;
			t[x].le = t[lson(x)].le;
			t[x].ri = t[rson(x)].ri;

			t[x].ans = 0;

			if (t[lson(x)].r != t[rson(x)].l) {

				if (t[lson(x)].len == t[lson(x)].le) {

					t[x].le += t[rson(x)].le;

				}
				if (t[rson(x)].len == t[rson(x)].ri) {

					t[x].ri += t[lson(x)].ri;

				}

				t[x].ans = t[lson(x)].ri + t[rson(x)].le;

			}

			t[x].ans = max({ t[x].ans, t[x].le, t[x].ri, t[lson(x)].ans, t[rson(x)].ans });

		}
	}

	void update(int il, int ir, int v, int x, int xl, int xr) {

		if (il > xr || ir < xl)return;

		if (il <= xl && xr <= ir) {

			t[x].l ^= 1;
			t[x].r ^= 1;

		}
		else {

			int m = (xl + xr) / 2;

			update(il, ir, v, lson(x), xl, m);
			update(il, ir, v, rson(x), m + 1, xr);

			t[x].len = t[lson(x)].len + t[rson(x)].len;
			t[x].l = t[lson(x)].l, t[x].r = t[rson(x)].r;
			t[x].le = t[lson(x)].le;
			t[x].ri = t[rson(x)].ri;
			t[x].ans = 0;

			if (t[lson(x)].r != t[rson(x)].l) {

				if (t[lson(x)].len == t[lson(x)].le) {

					t[x].le += t[rson(x)].le;

				}
				if (t[rson(x)].len == t[rson(x)].ri) {

					t[x].ri += t[lson(x)].ri;

				}

				t[x].ans = t[lson(x)].ri + t[rson(x)].le;

			}

			t[x].ans = max({ t[x].ans, t[x].le, t[x].ri, t[lson(x)].ans, t[rson(x)].ans });


		}

	}

	void update(int p, int v) {
		update(p, p, 1, 1, 0, n - 1);
	}

	int query() {
		return t[1].ans;
	}
};
int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		printf("Case #%d:\n", ++tc);

		int n, q;
		scanf("%d %d", &n, &q);

		vector <int> y(n);
		for (int i = 0; i < n; i++)y[i] = 1;

		Segment tree(y);

		while (q--) {

			int x;
			scanf("%d", &x);

			x--;

			tree.update(x, 1);

			printf("%d\n", tree.query());

		}

	}

}