#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

int n;

ll I[100003];
ll F(ll a) {
	ll ret = 0;
	for (ll i = 2; i <= n; i++) {
		ret += abs(I[1] + a*(i - 1) - I[i]);
	}return ret;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &I[i]);
	}

	ll min = -I[n], max = I[n];
	int x = 75; // 200

	while (min != max && x--) {
		ll l = (2 * min + max) / 3;
		ll r = (min + max * 2) / 3;

		if (F(l) > F(r)) { // find for interval(function)'s minimum
			min = l;
		} // F(min) < F(max) : find for interval(function)'s maximum
		else {
			max = r;
		}
	}

	printf("%lld\n", F((min + max) / 2));
} // ternary search