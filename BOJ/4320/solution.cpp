#include <stdio.h>
#define ll long long

int main() {

	ll n, o;
	while (scanf("%lld", &n) == 1 && n) {

		o = n;
		if (n < 0)n *= -1LL;

		int ans = 1;
		for (ll i = 2; i*i <= n; i++) {

			if (n%i)continue;

			ll k = i;
			int c = 1;
			
			while (k < n) {
				k *= i;
				c++;
			}

			if (k == n) {
				if (o > 0 || c % 2) {
					ans = c;
					break;
				}
			}

		}

		printf("%d\n", ans);

	}

}