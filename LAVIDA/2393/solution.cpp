#include <stdio.h>
#include <memory.h>

int dp[30003][400];

int C[30003];
int L;
int n, d;

int M(int a, int b){ return a < b ? b : a; }

int dy(int c, int l){
	if (c > L)return 0;

	int x = l + 300 - d;

	if (dp[c][x] != -1)return dp[c][x];

	dp[c][x] = C[c] + M(dy(c + l, l), dy(c + l + 1, l + 1));

	if (l > 1)dp[c][x] = M(dp[c][x], C[c] + dy(c + l - 1, l - 1));

	return dp[c][x];
}

int main()
{
	//freopen("large_dat13.in", "r", stdin);
	//freopen("large_dat13.out", "w", stdout);

	scanf("%d %d", &n, &d);

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		L = L < a ? a : L;
		C[a]++;
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(d, d));
}