#include <stdio.h>

#define ll long long

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		ll a, b;
		scanf("%lld %lld", &a, &b);

		ll c = (b - a) + 1;
		ll d = (b + a);

		if (c & 1)d >>= 1;
		else
			c >>= 1;

		printf("Scenario #%d:\n", ++tc);
		printf("%lld\n\n", c*d);

	}

}