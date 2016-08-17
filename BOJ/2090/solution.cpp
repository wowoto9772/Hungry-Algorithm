#include <stdio.h>

#define ll long long

ll p[13];

ll gcd(ll a, ll b) {

	ll m = 1;
	
	while (m) {
		m = a % b;
		a = b;
		b = m;
	}
	
	return a;
}

int main() {

	int n;
	scanf("%d", &n);

	ll m = 1;

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &p[i]);
		m *= p[i];
	}

	ll s = 0;

	for (int i = 1; i <= n; i++) {
		s += m / p[i];
	}

	ll g = gcd(s, m);

	printf("%lld/%lld\n", m / g, s / g);

}