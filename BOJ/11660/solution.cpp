#include <stdio.h>
#define ll long long

ll dp[1027][1027];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a;
		}
	}

	for (int i = 1; i <= m; i++) {
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &b, &x, &y);

		printf("%lld\n", dp[x][y] - dp[a - 1][y] - dp[x][b - 1] + dp[a - 1][b - 1]);
	}

}