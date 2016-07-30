#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		ll k;
		scanf("%lld", &k);

		ll l = 1, r = (1e+10) + 1, m;

		ll ans = 0;

		while (l <= r) {
			
			m = (l + r) / 2;

			ll cmp = (1 + m) * (m) / 2;

			if (cmp <= k) {
				ans = max(ans, m);
				l = m + 1;
			}
			else
				r = m - 1;

		}

		printf("%lld\n", ans);

	}

}