#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

int g[500003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &g[i]);
	}

	sort(g + 1, g + 1 + n);

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += abs(i - g[i]);
	}

	printf("%lld\n", ans);

}