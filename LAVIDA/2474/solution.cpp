#include <stdio.h>
#define ll long long

ll dp[33];

int main() {

	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= 30; i += 2) {
		dp[i] = dp[i - 2] * 3LL;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2LL;
		}
	}

	// dp[0] = 0;

	int n;

	while (scanf("%d", &n) == 1 && n > -1) {
		printf("%lld\n", dp[n]);
	}

}