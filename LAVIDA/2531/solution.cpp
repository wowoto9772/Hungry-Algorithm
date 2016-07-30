#include <stdio.h>

int k, n;

double dp[13][103];

double dy(int c, int s) {

	if (s == n)return 1.0;
	if (dp[c][s] >= 0)return dp[c][s];

	dp[c][s] = 0.0;

	int l = c - 1, r = c + 1;

	if (l < 0)l = 0;
	if (r > k)r = k;

	for (int i = l; i <= r; i++) {
		dp[c][s] += (double)dy(i, s + 1) / (k + 1);
	}

	return dp[c][s];

}

int main() {


	while (scanf("%d %d", &k, &n) == 2) {

		for (int i = 0; i <= k; i++)for (int j = 0; j <= n; j++)dp[i][j] = -1.0;

		double ans = 0.0;

		for (int i = 0; i <= k; i++) {
			ans += (double)dy(i, 1) / (k + 1);
		}

		printf("%.5lf\n", ans * 100);

	}

}