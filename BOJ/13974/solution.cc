#include <stdio.h>

int f[5003], g[5003];
int dp[5003][5003];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			scanf("%d", &f[i]);
			f[i] += f[i - 1];
			g[i - 1] = i;
		}

		// knuth optimization

		for (int k = 2; k <= n; k++){
			int i = 0;
			for (int j = k; j <= n;){
				int l = g[i], r = g[i + 1];
				dp[i][j] = (1 << 31) - 1;
				for (int x = l; x <= r; x++){
					if (dp[i][j] > dp[i][x] + dp[x][j]){
						dp[i][j] = dp[i][x] + dp[x][j]; 
						g[i] = x;
					}
				}
				dp[i][j] += f[j] - f[i];
				i++, j++;
			}
		}

		printf("%d\n", dp[0][n]);

	}

}