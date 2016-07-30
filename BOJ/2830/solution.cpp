#include <stdio.h>
#define ll long long

int y[1000003];
int s[32];

int main() {

	int n;
	scanf("%d", &n);

	int x = 0;

	for (int i = 0; i < n; i++) {

		scanf("%d", &y[i]);

		int x = y[i];

		for (int i = 0; x; i++) {
			s[i] += x & 1;
			x >>= 1;
		}
		

	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {

		int z[23] = { 0 };
		int x = y[i];

		for (int j = 0; x; j++) {
			s[j] -= x & 1;
			z[j] = x & 1;
			x >>= 1;
		}

		int tot = n - i - 1;

		for (int j = 0; j < 20; j++) {
			if (z[j]) {
				ans += (ll)(1 << j) * (tot - s[j]);
			}
			else {
				ans += (ll)(1 << j) * (s[j]);
			}
		}

	}

	// 7^3 + 3^5 + 7^5	= 12

	printf("%lld\n", ans);

}