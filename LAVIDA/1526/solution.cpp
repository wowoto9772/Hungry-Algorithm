#include <stdio.h>
#include <memory.h>
#include <limits.h>

int h, w;

char str[44][14];

int dp[1 << 10][42][12];

int m(int a, int b){ return a < b ? a : b; }

int dy(int n, int i, int j){
	if (i >= h)return 0;
	if (j >= w){
		return dy(n, i + 1, 0);
	}
	if (dp[n][i][j] != -1)return dp[n][i][j];

	dp[n][i][j] = INT_MAX;

	int n_ = (n >> 1);

	// now block is checked ? or 'o'
	if (n & 1 || str[i][j] == 'o'){
		dp[n][i][j] = dy(n_, i, j + 1);
	}

	// antenna located in h * w grid
	// 2 * 1
	// next(bot) block checked
	if(i < h-1)dp[n][i][j] = m(dp[n][i][j], 1 + dy(n_ | (1 << (w - 1)), i, j + 1));
	// 1 * 2
	// next(right) block checked
	if(j < w-1)dp[n][i][j] = m(dp[n][i][j], 1 + dy(n_ | 1, i, j + 1));

	return dp[n][i][j];
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &h, &w);

		for (int i = 0; i < h; i++)scanf("%s", str[i]);

		memset(dp, 0xff, sizeof(dp));

		printf("%d\n", dy(0, 0, 0));
	}
}