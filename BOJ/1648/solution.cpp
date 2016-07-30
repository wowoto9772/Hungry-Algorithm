#include <stdio.h>
#include <algorithm>

#define mod 9901
#define H 14
#define W 14

using namespace std;

int dp[H*W + 1][1 << W] = { 0 };

int main()
{
	int h, w;
	while (scanf("%d %d", &w, &h) == 2) {

		if (w < 0 || h < 0)break;

		for (int i = 0; i < h*w; i++)for (int j = 0; j < (1 << w); j++)dp[i][j] = 0;

		dp[w*h][0] = 0;

		dp[0][0] = 1;

		for (int x = 0; x < h*w; x++)
		{
			for (int i = 0; i < (1 << w); i++)
			{
				if (i & 1) {
					dp[x + 1][i >> 1] += dp[x][i];
					dp[x + 1][i >> 1] %= mod;
				}
				else
				{
					if (!(i & 3) && x%w != w - 1) {
						dp[x + 1][(i >> 1) + 1] += dp[x][i];
						dp[x + 1][(i >> 1) + 1] %= mod;
					}
					dp[x + 1][(i >> 1) | (1 << (w - 1))] += dp[x][i];
					dp[x + 1][(i >> 1) | (1 << (w - 1))] %= mod;
				}
			}
		}

		dp[0][0] = 0;

		printf("%d\n", dp[w*h][0] % mod);

	}

	return 0;
}