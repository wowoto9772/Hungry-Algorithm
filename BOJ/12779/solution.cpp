#include <stdio.h>
#include <math.h>

#define ll long long

ll gcd(ll a, ll b) {
	ll m = 1;
	while (m) {
		m = a%b;
		a = b;
		b = m;
	}return a;
}

int main() {

	ll a, b;
	scanf("%lld %lld", &a, &b);

	ll t = b - a;
	ll s = floor(sqrt(b)) - floor(sqrt(a));
	ll g = gcd(s, t);

	if (!s)printf("0\n");
	else {
		printf("%lld/%lld\n", s / g, t / g);
	}
}