#include <stdio.h>
#define ll unsigned long long

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int a;
		scanf("%d", &a);

		int x[8];

		if (a == 1) {
			scanf("%d.%d.%d.%d.%d.%d.%d.%d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7]);

			ll ans = 0;
			ll k = 1;

			for (int i = 7; i >= 0; i--) {
				ans += x[i] * k;
				k <<= 8LL;
			}

			printf("%llu", ans);
		}
		else {

			ll k;
			scanf("%llu", &k);
			for (int i = 7; i >= 0; i--) {
				x[i] = k % 256;
				k >>= 8;
			}

			for (int i = 0; i < 8; i++) {
				if (i)printf(".");
				printf("%d", x[i]);
			}
		}

		printf("\n");

	}

}