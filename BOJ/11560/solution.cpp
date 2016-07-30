#include <stdio.h>
#define llu unsigned long long

llu dp[23][223];
int k, n;

llu dy(int c, int x) {

	if (c == k + 1)return x == n;
	if (dp[c][x] != -1)return dp[c][x];

	dp[c][x] = 0;

	for (int i = 0; x + i <= n && i <= c; i++)dp[c][x] += dy(c + 1, x + i);

	return dp[c][x];

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d %d", &k, &n);

		for (int i = 1; i <= k; i++)for (int j = 0; j <= n; j++)dp[i][j] = -1;

		printf("%llu\n", dy(1, 0));

	}

}