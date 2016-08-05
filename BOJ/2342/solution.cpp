#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int a[100003];
int dp[100003][5][5];

int cost(int a, int b) {

	if (a == b)return 1;
	else {
		if (a == 0)return 2;
		else {
			if (a & 1) {
				if (b & 1)return 4;
				return 3;
			}
			else {
				if (b & 1)return 3;
				return 4;
			}
		}
	}

}

int main() {

	int n, t = 0;
	while (scanf("%d", &n) == 1) {

		if (n == 0) {

			break;

		}
		else {
			a[++t] = n;
		}
	}

	n = t;

	int p = 0;

	for (int x = 0; x <= n; x++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[x][j][k] = INT_MAX;
			}
		}
	}

	dp[0][0][0] = 0;

	for (int c = 1; c <= n; c++) {

		int l = a[c];

		for (int r = 0; r < 5; r++) {

			if (l == r)continue;

			for (int p = 0; p < 5; p++) {

				int cst = cost(min(p, l), max(p, l));

				if (dp[c-1][p][r] != INT_MAX && dp[c][l][r] > dp[c - 1][p][r] + cst) {
					dp[c][l][r] = dp[c - 1][p][r] + cst;
				}

				if (dp[c-1][r][p] != INT_MAX && dp[c][r][l] > dp[c - 1][r][p] + cst) {
					dp[c][r][l] = dp[c - 1][r][p] + cst;
				}

			}
		}

	}

	int ans = INT_MAX;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans = min(ans, dp[n][i][j]);
		}
	}

	printf("%d\n", ans);

}