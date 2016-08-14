#include <stdio.h>

#include <vector>
#include <algorithm>

#define ll long long
#define mod 1000000007LL

using namespace std;

class Segment {
public:

	int n;
	vector <ll> t;

	Segment(vector <ll> &e) {
		
		n = e.size();

		t.resize(n<<1);

		init(e, 1, 0, n - 1); 

	} // init(O(2*n-1))

	ll init(vector <ll> &e, int x, int xl, int xr) {

		if (xl == xr) {
			t[x] = e[xl];
		}
		else {
			int m = (xl + xr) / 2;
			t[x] = (init(e, x << 1, xl, m) * init(e, (x << 1) | 1, m + 1, xr)) % mod;
		}

		return t[x];

	}

	ll query(int il, int ir, int x, int xl, int xr) {
		if (ir < xl || xr < il) {
			return 1;
		}
		else if (il <= xl && xr <= ir) {
			return t[x];
		}
		else {
			int m = (xl + xr) / 2;
			return (query(il, ir, x * 2, xl, m) * query(il, ir, x * 2 + 1, m + 1, xr)) % mod;
		}
	}

	ll query(int il, int ir) {
		return query(il, ir, 1, 0, n - 1);
	}

	ll update(int p, ll v, int x, int xl, int xr) {

		if (p < xl || xr < p) {
			// not need change
		}
		else if (xl == xr) {
			t[x] = v;
		}
		else {
			int m = (xl + xr) / 2;
			t[x] = (update(p, v, x * 2, xl, m) * update(p, v, x * 2 + 1, m + 1, xr)) % mod;
		}

		return t[x];
	}

	ll update(int p, ll v) {
		return update(p, v, 1, 0, n - 1);
	}
};

int main() {

	int n, q, p;
	scanf("%d %d %d", &n, &q, &p);

	vector <ll> e(n);

	int l = 1;

	while (l < n)l <<= 1;

	for (int i = 1; i <= l - n; i++)e.push_back(1LL);

	for (int i = 0; i < n; i++) {

		scanf("%lld", &e[i]);

	}

	Segment tree(e);

	q += p;

	while (q--) {

		int x, l, r;
		scanf("%d %d %d", &x, &l, &r);

		l--;

		if (x == 2) {

			r--;

			if (l > r)swap(l, r);

			printf("%lld\n", tree.query(l, r));

		}
		else {

			tree.update(l, r);

		}

	}

}