#include <stdio.h>

#define ll long long

int main() {

	ll r, c, n;
	scanf("%lld %lld %lld", &r, &c, &n);

	r = r / n + ((r%n) ? 1 : 0);
	c = c / n + ((c%n) ? 1 : 0);

	printf("%lld\n", r * c);

}