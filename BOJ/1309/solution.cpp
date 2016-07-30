#include <stdio.h>

#define mod 9901

int dp[100003][2][2];

int main() {

	int n;
	scanf("%d", &n);

	dp[0][0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0][1] = dp[i - 1][0][0] + dp[i - 1][1][0];
		dp[i][0][1] %= mod;

		dp[i][1][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
		dp[i][1][0] %= mod;

		dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0];
		dp[i][0][0] %= mod;
	}

	printf("%d\n", (dp[n][0][0] + dp[n][0][1] + dp[n][1][0]) % mod);

}