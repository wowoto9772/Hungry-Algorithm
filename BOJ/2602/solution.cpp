#include <stdio.h>
#include <string.h>

int dp[23][103][3];

char tar[23];
char sexy[2][103];

int m, n;

int dy(int c, int x, int y) {

	if (c == m)return 1;

	int &ret = dp[c][x][y];

	if (ret != -1)return ret;

	ret = 0;

	for (int i = x + 1; i <= n; i++) {

		if (sexy[!y][i] == tar[c + 1]) {

			ret += dy(c + 1, i, !y);

		}

	}

	return ret;

}

int main() {

	scanf("%s", tar + 1);

	m = strlen(tar + 1);

	for (int i = 0; i < 2; i++)scanf("%s", sexy[i] + 1);

	n = strlen(sexy[0] + 1);

	dp[0][0][0] = dp[0][0][1] = -1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	printf("%d\n", dy(0, 0, 0) + dy(0, 0, 1));

}