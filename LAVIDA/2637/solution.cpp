#include <stdio.h>

#define smax(a, b) (a < b ? b : a)

int v[202][3];
int dp[202][202][3];
int max(int a, int b){ return a < b ? b : a; }

int main(){
	int n, k;
	while (scanf("%d %d", &n, &k) == 2 && n){
		for (int i = 1; i <= n; i++){
			scanf("%d %d", &v[i][1], &v[i][2]);
			v[i][0] = v[i][1] + v[i][2];
		}

		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= k && j <= i; j++){
				if(j < i)dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j][1], dp[i - 1][j][2])) + v[i][0];
				if (j){
					dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + v[i][1];
					dp[i][j][2] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + v[i][2];
				}
			}
		}
		printf("%d\n", max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])));
	}
}