#include <stdio.h>

#define ll long long

ll cnt(int n, int k) {

	ll c[433] = { 0 };

	for (int i = n - k + 1; i <= n; i++) {

		int v = i;

		for (int j = 2; j*j <= v; j++) {
			if (v%j)continue;

			while (!(v%j)) {
				c[j]++;
				v /= j;
			}
		}

		if (v != 1) {
			c[v]++;
		}
	}

	for (int i = 2; i <= k; i++) {

		int v = i;

		for (int j = 2; j*j <= v; j++) {
			if (v%j)continue;

			while (!(v%j)) {
				c[j]--;
				v /= j;
			}
		}

		if (v != 1) {
			c[v]--;
		}

	}

	ll ret = 1;
	for (int i = 2; i <= n; i++) {
		ret *= (c[i] + 1);
	}

	return ret;

}

int main() {

	int n, k;
	while (scanf("%d %d", &n, &k) == 2) {
		printf("%lld\n", cnt(n, k));
	}

}