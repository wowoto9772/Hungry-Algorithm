#include <stdio.h>

double dp[1 << 8][1 << 8][2];

int n;

double p[10][10];

double dy(int x, int y, int k) {

	if (x == (1 << n) - 1)return 0.0;
	if (dp[x][y][k] > -0.5)return dp[x][y][k];

	if (k)dp[x][y][k] = 987654321.0;
	else
		dp[x][y][k] = 0.0;


	for (int i = 0; i < n; i++) {
		if (x & (1 << i))continue;
		for (int j = 0; j < n; j++) {
			if (y & (1 << j))continue;

			double nv = p[i][j] + dy(x | (1<<i), y | (1<<j), !k);

			if (k) {
				if (dp[x][y][k] > nv) {
					dp[x][y][k] = nv;
				}
			}
			else {
				if (dp[x][y][k] < nv) {
					dp[x][y][k] = nv;
				}
			}
		}
	}

	return dp[x][y][k];

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lf", &p[i][j]);
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[i][j][0] = dp[i][j][1] = -1.0;
		}
	}

	
	double win = dy(0, 0, 0), lose = dy(0, 0, 1);

	printf("%.8lf %.8lf\n", win, lose);

}