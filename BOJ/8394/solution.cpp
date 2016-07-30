#include <stdio.h>
#define mod 10

int dp[10000003][2];

int main() {

	int n;
	scanf("%d", &n);

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		if (i >= 2) {
			dp[i][1] = dp[i - 2][1] + dp[i-2][0];
			dp[i][1] %= mod;
		}
		dp[i][0] = dp[i - 1][0] + dp[i-1][1];
		dp[i][0] %= mod;
	}

	printf("%d\n", (dp[n][1] + dp[n][0]) % mod);

}