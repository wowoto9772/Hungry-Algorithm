#include <stdio.h>

#define mod 1000

int dp[1000003][2];

int main() {

	int a, b, d, n;
	scanf("%d %d %d %d", &a, &b, &d, &n);

	dp[0][0] = dp[0][1] = 1;

	for (int i = 1; i <= n; i++) {

		if (i >= a) {
			dp[i][0] = (dp[i - a][1] + mod);
			if (i - b >= 0)dp[i][0] -= dp[i - b][1];
			dp[i][0] %= mod;
		}

		dp[i][1] = dp[i - 1][1] + dp[i][0];

		dp[i][1] %= mod;

	}

	printf("%d\n", (dp[n][1] - dp[n - d][1] + mod) % mod);

}