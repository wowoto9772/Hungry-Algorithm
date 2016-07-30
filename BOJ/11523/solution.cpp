#include <stdio.h>
#include <vector>

using namespace std;

int P[40], top;
bool p[105];

#define ll unsigned long long

ll ncase(int lo, int lt) {

	// ltt C lo * ltt C lo

	int ltt = lo + lt;

	int v = ltt;

	vector <ll> c;

	for (int i = 0; i < top && P[i] <= v; i++) {

		c.push_back(0);

		int g = P[i];
		while (g <= v) {
			c.back() += 2 * (v / g);
			g *= P[i];
		}

	}

	v = lo;

	for (int i = 0; i < top && P[i] <= v; i++) {

		int g = P[i];
		while (g <= v) {
			c[i] -= 2 * (v / g);
			g *= P[i];
		}

	}

	v = lt;

	for (int i = 0; i < top && P[i] <= v; i++) {

		int g = P[i];
		while (g <= v) {
			c[i] -= 2 * (v / g);
			g *= P[i];
		}

	}

	ll ret = 1;

	for (int i = 0; i < c.size(); i++) {

		for (int j = 1; j <= c[i]; j++) {

			ret *= P[i];

		}

	}

	return ret;

}

int main() {

	for (int i = 2; i <= 100; i++) {
		if (!p[i]) {
			P[top++] = i;
			for (int j = i*i; j <= 100; j += i) {
				p[j] = true;
			}
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int a, n;
		scanf("%d %d", &a, &n);

		ll ans = 0;

		for (int i = n; i >= 0; i-=4) {

			int o = i, t = (n - i) / 2;

			if (o <= t) {

				ans += ncase(o / 2, t / 2);

			}

		}

		printf("%d %llu\n", a, ans);

	}

}