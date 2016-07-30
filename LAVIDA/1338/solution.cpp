#include <stdio.h>

int I[36][36];

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n > 0){
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%1d", &I[i][j]);
		long long dp[36][36] = { 0 };

		dp[n][n] = 1;

		for (int i = n; i >= 1; i--){
			for (int j = n; j >= 1; j--){
				if (i == n && j == n)continue;
				if (i + I[i][j] <= n)dp[i][j] += dp[i + I[i][j]][j];
				if (j + I[i][j] <= n)dp[i][j] += dp[i][j + I[i][j]];
			}
		}

		printf("%lld\n", dp[1][1]);
	}

}