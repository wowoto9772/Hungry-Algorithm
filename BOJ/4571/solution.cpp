#include <stdio.h>
#define ll long long

int c(ll a) {
	int ret = 0;
	while (a / 10 != 0) {
		ret++, a /= 10;
	}return ++ret;
}

int main()
{

	ll n, m;
	int tc = 0;

	while (scanf("%lld %lld", &n, &m) == 2) {
		
		if ((n | m) == 0)break;
		
		printf("Problem %d\n", ++tc);

		ll ans = n * m;
		
		int dg = c(ans);
				
		for (int i = 1; i <= dg - c(n); i++)printf(" ");		
		printf("%lld\n", n);

		for (int i = 1; i <= dg - c(m); i++)printf(" ");
		printf("%lld\n", m);

		for (int i = 1; i <= dg; i++)printf("-");
		printf("\n");

		int s = c(m), z = 0, t = 0, k = 0;

		for (int i = 1; i <= s; i++) {
			if (m % 10) {
				for (int i = 1; i <= dg - c((m % 10) * n) - t; i++)printf(" ");

				printf("%lld", (m % 10) * n);

				for (int i = 1; i <= z; i++)printf("0");
				printf("\n");
				z = 0;
				k++;
			}
			else
				z++;
			t++;
			m /= 10;
		}
		
		if (k != 1) {
			for (int i = 1; i <= dg; i++)printf("-");
			printf("\n%lld\n", ans);
		}
	}
}