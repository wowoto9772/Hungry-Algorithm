#include <stdio.h>

#define ll long long

ll e[103];

int main() {

	int t;
	scanf("%d", &t);
	
	while (t--) {

		int n, m;
		scanf("%d %d", &n, &m);

		ll x = 0, y = 0;

		for (int i = 1; i <= m; i++) {

			ll k;
			scanf("%lld", &k);

			x = x * 10LL + k;
		}

		ll d = 1;

		for (int i = 1; i <= m; i++) {

			ll k;
			scanf("%lld", &k);

			y = y * 10LL + k;

			d *= 10LL;

		}

		int c = 0;

		for (int i = 1; i <= n; i++) {

			scanf("%lld", &e[i]);

		}

		for (int i = n + 1; i < n + m; i++)e[i] = e[i - n];

		ll a = 0;

		for (int i = 1; i < n+m; i++) {

			a = a * 10LL + e[i];

			if (i > m)a -= e[i - m] * d;

			if (i >= m && x <= a && a <= y)c++;

		}

		printf("%d\n", c);

	}

}