#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

int main() {

	int n;
	scanf("%d", &n);

	ll c, p;
	scanf("%lld", &p);

	ll lo = LLONG_MIN, hi = LLONG_MAX;
	
	for (int i = 2; i <= n; i++) {
		scanf("%lld", &c);

		lo = max(lo, p);
		hi = min(hi, c);

		ll tmp = lo;
		c <<= 1;

		lo = c - hi;
		hi = c - tmp;

	}

	printf("%lld\n", max(0LL, hi - lo + 1));

}