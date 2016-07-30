#include <stdio.h>
#define mod 1000000000

int dp[103][10];

int main(){

	for (int i = 1; i <= 9; i++)dp[1][i] = 1;

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++){

		for (int j = 0; j <= 9; j++){
			if (j + 1 <= 9){
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
			if (j - 1 >= 0){
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= mod;
			}
		}

	}

	int ans = 0;

	for (int i = 0; i <= 9; i++){
		ans += dp[n][i];
		ans %= mod;
	}

	printf("%d\n", ans);

}