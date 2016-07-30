#include <stdio.h>
#define ll long long

int main() {

	ll k;
	scanf("%lld", &k);

	ll a = 0;
	ll c = 1;

	while (k) {
		if (k & 1)a += c;
		c *= 3LL;
		k >>= 1;
	}

	printf("%lld\n", a);

}

/*
500000000000
*/