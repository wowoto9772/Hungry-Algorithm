#include <stdio.h>

long long dp[808][808][2];

int main(){
	int n;
	scanf("%d", &n);

	dp[400][400][0] = 1; // init_value

	for (int i = 1; i <= n; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		for (int a = 0; a <= 800; a++){
			for (int b = 0; b <= 800; b++){
				dp[a][b][i % 2] = dp[a][b][(i - 1) % 2];
			}
		}

		for (int a = 0; a <= 800; a++){
			for (int b = 0; b <= 800; b++){
				if (dp[a][b][(i - 1) % 2]){
					dp[a + x][b + y][i % 2] += dp[a][b][(i - 1) % 2];
				}
			}
		}

	}

	printf("%lld\n", dp[400][400][n % 2] - 1); // init_value
}