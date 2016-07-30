#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[100103];

int main() {

	int n;
	scanf("%d", &n);

	int a, b;
	scanf("%d %d", &a, &b);

	int d;
	scanf("%d", &d);

	dp[a] = d;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &d);
		for (int j = 100000; j >= 1; j--) {
			if (dp[j])dp[j + b] = max(dp[j + b], dp[j] + d);
		}
	}

	int ans = 0;
	for (int i = 1; i <= 100100; i++)ans = max(ans, dp[i] / i);

	printf("%d\n", ans);

}