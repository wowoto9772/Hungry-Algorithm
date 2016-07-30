#include <stdio.h>
#include <memory.h>

int h, w;

long long dp[1 << 11][13][13];

long long dy(int n, int i, int j){
	if (i >= h)return 1;
	if (j >= w){
		return dy(n, i + 1, 0);
	}
	if (dp[n][i][j] != -1)return dp[n][i][j];

	dp[n][i][j] = 0;

	int n_ = (n >> 1);
	if (n & 1){
		return dp[n][i][j] = dy(n_, i, j + 1);
	}

	if (i < h - 1){
		dp[n][i][j] += dy(n_ | (1 << (w - 1)), i, j + 1);
	}

	if (j < w - 1 && !(n_ & 1)){
		n_ = n >> 2;
		dp[n][i][j] += dy(n_, i, j + 2);
	}

	return dp[n][i][j];
}
int main()
{
	while (scanf("%d %d", &h, &w) == 2){
		if (h == w && !h)break;
		if (h % 2 && w % 2)printf("0\n");
		else{
			memset(dp, 0xff, sizeof(dp));
			printf("%lld\n", dy(0, 0, 0));
		}
	}
}