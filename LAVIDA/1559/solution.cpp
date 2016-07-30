#include <stdio.h>

long long dp[53];

int main()
{
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 50; i+=2){
		for (int j = 0; j < i; j+=2){
			dp[i] += dp[2] * dp[j] * dp[i-2-j];
			// 2 man's position is not changed.
		}
	}

	dp[0] = 0;

	int t;
	while (scanf("%d", &t) == 1){

		while (t--){

			int n;
			scanf("%d", &n);

			printf("%lld\n", dp[n]);

		}

	}
}

// Catalan numbers