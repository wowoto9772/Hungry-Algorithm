#include <stdio.h>
#define ll long long

int main() {

	ll a;
	int b, c;
	scanf("%lld %d %d", &a, &b, &c);

	a %= c;

	ll d = 1;

	while (b) {

		if (b & 1) {
			d *= a;
			d %= c;
		}

		b >>= 1;
		a *= a;
		a %= c;
	}

	d %= c;

	printf("%lld\n", d);

}