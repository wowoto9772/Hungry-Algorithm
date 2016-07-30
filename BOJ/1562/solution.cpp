#include <stdio.h>
#define mod 1000000000

long long dp[103][10][10][10];
// len, small, big, last

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++)dp[1][i][i][i] = 1LL;

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= 9; j++){
			for (int k = j; k <= 9; k++){
				for (int m = j; m <= k; m++){
					int x = m - 1;
					if (x >= 0){
						int mj = j > x ? x : j;
						dp[i][mj][k][x] += dp[i - 1][j][k][m];
						dp[i][mj][k][x] %= mod;
					}

					x = m + 1;
					if (x <= 9){
						int Mk = k < x ? x : k;
						dp[i][j][Mk][x] += dp[i - 1][j][k][m];
						dp[i][j][Mk][x] %= mod;
					}
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++){
		ans += dp[n][0][9][i];
		ans %= mod;
	}

	printf("%lld\n", ans);
}