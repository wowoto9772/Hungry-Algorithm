#include <stdio.h>

#define ll long long

int main() {

	ll n, k;
	
	while (scanf("%lld %lld", &n, &k) == 2) {

		ll c = n;

		while (c / k) {
			
			n += c / k;

			ll add = c / k;

			c -= c / k * k;
			
			c += add;

		}

		printf("%lld\n", n);

	}

}