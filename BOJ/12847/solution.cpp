#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll w[100003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		w[i] += w[i - 1];
	}

	ll ans = 0;
	for (int i = m; i <= n; i++) {
		ans = max(ans, w[i] - w[i - m]);
	}

	printf("%lld\n", ans);

}