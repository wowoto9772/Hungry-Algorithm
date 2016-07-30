#include <stdio.h>
#include <memory.h>

int dp[303][303];
int I[303][303];

int M(int a, int b){ return a < b ? b : a; }

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	memset(dp, 0xff, sizeof(dp));
	for (int i = 1; i <= k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a <= b)if (I[a][b] < c)I[a][b] = c;
	}

	dp[1][1] = 0;
	int ans = 0;
	for (int k = 1; k<m; k++){
		for (int i = 2; i <= n; i++){
			for (int j = 1; j<i; j++){
				if (I[j][i] && dp[j][k] != -1){
					dp[i][k + 1] = M(dp[i][k + 1], dp[j][k] + I[j][i]);
				}
			}
		}
		ans = M(ans, dp[n][k + 1]);
	}

	printf("%d\n", ans);
}