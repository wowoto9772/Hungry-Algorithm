#include <stdio.h>
#include <memory.h>

int n;
int dp[303][3];
int I[303];

int M(int a, int b){ return a < b ? b : a; }

int dy(int c, int s){
	if (c == n)return I[c];

	if (dp[c][s] != -1)return dp[c][s];

	dp[c][s] = 0;

	if (c < n && s < 2)dp[c][s] = M(dp[c][s], I[c] + dy(c + 1, s+1));
	if (c < n - 1)dp[c][s] = M(dp[c][s], I[c] + dy(c + 2, 1));

	if (!dp[c][s])dp[c][s] = -3000001;

	return dp[c][s];
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &I[i]);

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(0, 0));
}