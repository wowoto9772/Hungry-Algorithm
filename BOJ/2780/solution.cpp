#include <stdio.h>
#define mod 1234567

int a[][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {0, -1, -1} };
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int dp[1003][4][3];

int dy(int n, int r, int c) {

	if (dp[n][r][c] != -1)return dp[n][r][c];

	int &ret = dp[n][r][c];
	
	ret = 0;

	for (int i = 0; i < 4; i++) {
		
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= 4 || nc >= 3)continue;

		if (a[nr][nc] == -1)continue;

		ret += dy(n + 1, nr, nc);

		ret %= mod;

	}

	return ret;

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					dp[i][j][k] = -1 * ((i == n) ? -1 : 1);
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				ans += dy(1, i, j);
				ans %= mod;
			}
		}
		
		ans += dy(1, 3, 0);
		ans %= mod;

		printf("%d\n", ans);

	}

}