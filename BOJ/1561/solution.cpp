#include <stdio.h>
#include <limits.h>
#include <algorithm>

#define ll long long

using namespace std;

ll e[10003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++) {
		scanf("%d", &e[i]);
	}

	ll l = 0, r = LLONG_MAX>>1, m;

	ll ans = LLONG_MAX>>1;

	while (l <= r) {

		m = (l + r) / 2;

		ll c = 0;

		if (m > 0)c += k;
		ll d = 0;

		for (int i = 1; i <= k; i++) {
			c += max((m-1), 0LL) / e[i];
			d += (m % e[i]) == 0;
			if (c > n)break;
		}

		if (c < n && c + d >= n) {
			for (int i = 1; i <= k; i++) {
				if (m%e[i])continue;
				c++;

				if (c == n) {
					printf("%d\n", i);
					return 0;
				}
			}
		}

		if (c >= n) {
			ans = min(ans, m);
			r = m - 1;
		}
		else {
			l = m + 1;
		}

	}

}