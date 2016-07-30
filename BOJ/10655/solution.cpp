#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

ll x[100003], y[100003];
ll d[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		if (i > 1) {
			d[i] = d[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
		}
	}

	ll ans = LLONG_MAX;

	for (int i = 2; i < n; i++) {
		ans = min(ans, d[i - 1] + (d[n] - d[i + 1]) + abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]));
	}

	printf("%lld\n", ans);

}