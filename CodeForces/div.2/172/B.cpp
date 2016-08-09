#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

int main() {

	ll x, y, n;
	scanf("%lld %lld %lld", &x, &y, &n);

	double ans = 998899868686LL;

	ll l, r;

	for (ll b = 1; b <= n; b++) {

		ll A = x*b;

		ll _a = A / y;
		
		ll s = (_a - 1), e = (_a + 1);

		for (ll a = s; a <= e; a++) {
			double tmp = (double)x / y;
			double tmp2 = (double)a / b;

			double tt = tmp - tmp2;
			tt = abs(tt);
			if (ans > tt) {
				ans = tt;
				l = a, r = b;
			}
		}

	}

	printf("%lld/%lld\n", l, r);

}