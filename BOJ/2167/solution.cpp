#include <stdio.h>
#define ll long long

ll dp[303][303];

int main(){
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			int a;
			scanf("%d", &a);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a;
		}
	}

	int m;
	scanf("%d", &m);

	for (int i = 1; i <= m; i++){
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &b, &x, &y);

		printf("%lld\n", dp[x][y] - dp[a - 1][y] - dp[x][b-1] + dp[a - 1][b - 1]);
	}
}