#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

class ele {
public:

	ele() {}
	ele(int x, ll y) {
		b = x, c = y;
	}

	int b;
	ll c;

	bool operator<(const ele &A)const {
		if (c == A.c)return b > A.b;
		return c < A.c;
	}
};

ll a[36], b[36];

int main() {

	int n;
	scanf("%d", &n);

	vector < vector <ele> > le, ri;

	le.resize(n / 2 + 1);
	ri.resize(n / 2 + 1);

	int k = n / 2;

	for (int i = 0; i < n; i++)scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)scanf("%lld", &b[i]);

	for (int i = 0; i < (1 << k); i++) {

		int c = 0;
		ll m = 0;

		for (int j = 0; j < k; j++) {
			if (i & (1 << (k - 1 - j))) {
				c++;
				m += a[j];
			}
			else {
				m -= b[j];
			}
		}

		le[c].emplace_back(i, m);

	}

	for (int i = 0; i < (1 << k); i++) {

		int c = 0;
		ll m = 0;

		for (int j = k; j < n; j++) {
			if (i & (1 << (k - 1 - (j - k)))) {
				c++;
				m += a[j];
			}
			else {
				m -= b[j];
			}
		}

		ri[c].emplace_back(i, m);
	}

	for (int i = 0; i <= k; i++) {
		sort(le[i].begin(), le[i].end());
		sort(ri[i].begin(), ri[i].end());
	}

	ll ans = LLONG_MAX;
	int ax, ay;

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < le[i].size(); j++) {

			ll cmp = -le[i][j].c;

			int l = 0, r = ri[k - i].size() - 1, m;

			// [pleft target pright] pleft & pright : if same c, then big b

			// for pright
			int p = r;

			while (l <= r) {

				m = (l + r) / 2;

				if (ri[k - i][m].c >= cmp) {
					p = min(p, m);
					r = m - 1;
				}
				else if (ri[k - i][m].c < cmp)l = m + 1;

			}

			int cand[2] = { p, };

			int top = 1;

			if (p > 0) {

				// for pleft
				cmp = ri[k-i][p-1].c;

				l = 0, r = p - 1;

				int p = r;

				while (l <= r) {

					m = (l + r) / 2;

					if (ri[k - i][m].c >= cmp) {
						p = min(p, m);
						r = m - 1;
					}
					else if (ri[k - i][m].c < cmp)l = m + 1;

				}

				cand[top++] = p;

			}

			for (int x = 0; x < top; x++) {
				cmp = abs(le[i][j].c + ri[k - i][cand[x]].c);
				if (ans > cmp) {
					ans = cmp;
					ax = le[i][j].b, ay = ri[k - i][cand[x]].b;
				}
				else if (ans == cmp) {
					if (ax < le[i][j].b) {
						ax = le[i][j].b, ay = ri[k - i][cand[x]].b;
					}
					else if (ax == le[i][j].b && ay < ri[k - i][cand[x]].b) {
						ay = ri[k - i][cand[x]].b;
					}
				}
			}

		}
	}

	for (int i = k - 1; i >= 0; i--) {
		if (ax & (1 << i)) {
			printf("1 ");
		}
		else {
			printf("2 ");
		}
	}

	for (int i = k-1; i >= 0; i--) {
		if (ay & (1 << i)) {
			printf("1 ");
		}
		else {
			printf("2 ");
		}
	}

}

/*
	4
	1 1 1 1
	1 1 1 1
	
	1 1 2 2
*/