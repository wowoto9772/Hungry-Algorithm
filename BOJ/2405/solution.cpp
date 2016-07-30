#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll e[100003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &e[i]);
	}

	sort(e, e + n);

	int l = 0, r = n - 1;

	ll ans = 0;

	for (int i = 1; i < n - 1; i++) {
		ans = max(ans, abs(3 * e[i] - (e[0] + e[i] + e[i + 1])));
	}

	for (int i = 0; i < n - 2; i++) {
		ans = max(ans, abs(3 * e[i + 1] - (e[i] + e[i + 1] + e[n - 1])));
	}

	printf("%lld\n", ans);

}