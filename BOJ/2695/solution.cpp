#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[1003][55]; // dp[i][j] : interval 1 ~ i, can confirm j times.

int dy(int h, int k) {
	if (!h)return 0;
	if (dp[h][k])return dp[h][k];

	dp[h][k] = INT_MAX;
	for (int i = h; i >= 1; i--) { // confirm i
		dp[h][k] = min(dp[h][k], 1 + max(dy(i - 1, k - 1), dy(h - i, k)));
	}

	return dp[h][k];
}

int main()
{
	for (int i = 1; i <= 1000; i++)dp[i][1] = i;

	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k;
		scanf("%d %d", &k, &n);
		printf("%d\n", dy(n, k));
	}
}