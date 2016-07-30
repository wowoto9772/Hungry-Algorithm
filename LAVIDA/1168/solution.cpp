#include <stdio.h>
#include <limits.h>

int dp[505][505]; // dp[i][j] : interval 1 ~ i, can confirm j times.
int m(int a, int b){ return a < b ? a : b; }
int M(int a, int b){ return a < b ? b : a; }

int dy(int h, int k){
	if (!h)return 0;
	if (dp[h][k])return dp[h][k];

	dp[h][k] = INT_MAX;
	for (int i = h; i >= 1; i--){ // confirm i
		dp[h][k] = m(dp[h][k], 1 + M(dy(i - 1, k - 1), dy(h - i, k)));
	}

	return dp[h][k];
}

int main()
{
	for (int i = 1; i <= 500; i++)dp[i][1] = i;
	int t;
	scanf("%d", &t);

	while (t--){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", dy(n, k));
	}
}