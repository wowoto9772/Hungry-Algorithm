#include <stdio.h>

#define ll long long

ll conv(ll a, ll i) {

	ll k = 1;
	ll v = 0;

	while (a) {
		v += (a % 10) * k;
		if (a % 10 >= i)return -1;
		a /= 10;
		k *= i;
	}
	
	return v;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		ll p, q, r;
		scanf("%lld %lld %lld", &p, &q, &r);

		int a = 0;

		for (ll i = 2; i <= 50 && !a; i++) {

			if (conv(p, i) * conv(q, i) == conv(r, i)) {
				a = i;
			}

		}

		printf("%d\n", a);


	}

}