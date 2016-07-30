#include <stdio.h>

#define mod 10007

int dp[1003][10];

int main(){
	for (int i = 0; i < 10; i++)dp[1][i] = 1;

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++){
		for (int j = 9; j >= 0; j--){
			for (int k = j; k >= 0; k--){
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= mod;
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++)ans += dp[n][i];
	printf("%d\n", ans%mod);
}