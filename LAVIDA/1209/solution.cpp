#include <stdio.h>
#include <memory.h>

int c[302][22];
int dp[302][22];
int r[302][22];

int n, m;

int dy(int i, int j){
	if (j > m)return 0;
	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = 0;

	for (int k = n - i; k >= 0; k--){
		int cst = c[k][j] + dy(i + c[k][0], j + 1);
		if (dp[i][j] < cst){
			dp[i][j] = cst;
			r[i][j] = c[k][0];
		}
	}

	return dp[i][j];
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= m; j++)scanf("%d", &c[i][j]);
	}

	memset(dp, 0xff, sizeof(dp));

	int out = dy(0, 1);

	int i = 0, j = 1;

	int ans[22] = { 0 };  

	while (j < m){
		printf("%d ", r[i][j]);
		i += r[i][j];
		j++;
	}printf("%d\n%d\n", r[i][j], out);
}