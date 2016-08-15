#include <stdio.h>

#define mod 1000007

int n, m, c;

int dp[53][53][53][53];
int game[53][53];

int dy(int x, int y, int r, int v) {

	if (x == n - 1 && y == m - 1)return r == 0;

	int &ret = dp[x][y][r][v];

	if (ret != -1)return ret;

	ret = 0;

	if (x + 1 < n) {

		if (!game[x + 1][y])ret += dy(x + 1, y, r, v);
		else {
			if (v < game[x + 1][y])ret += dy(x + 1, y, r - 1, game[x + 1][y]);
		}

	}

	if (y + 1 < m) {

		if (!game[x][y + 1])ret += dy(x, y + 1, r, v);
		else {
			if (v < game[x][y + 1])ret += dy(x, y + 1, r - 1, game[x][y + 1]);
		}

	}

	return ret %= mod;

}

int main() {

	scanf("%d %d %d", &n, &m, &c);

	for (int i = 1; i <= c; i++) {

		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;

		game[a][b] = i;

	}

	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)for (int k = 0; k <= c; k++)for (int l = 0; l <= c; l++)dp[i][j][k][l] = -1;

	for (int i = 0; i <= c; i++)printf("%d ", dy(0, 0, i - (game[0][0] ? 1 : 0), game[0][0]));

}