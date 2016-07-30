#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[22][22][22];

int main()
{
	memset(dp, 0x2f, sizeof(dp));
	for (int i = 1; i <= 20; i++)for (int j = 1; j <= 20; j++)dp[i][j][1] = i*j;
	for (int x = 2; x <= 20; x++){
		for (int w = 1; w <= 20; w++){
			for (int h = 1; h <= 20; h++){
				if (w*h >= x){
					// width
					for (int w2 = 1; w2 < w; w2++){
						for (int l = 1; l < x; l++){
							dp[w][h][x] = min(dp[w][h][x], max(dp[w2][h][l], dp[w - w2][h][x - l]));
						}
					}

					// height
					for (int h2 = 1; h2 < h; h2++){
						for (int l = 1; l < x; l++){
							dp[w][h][x] = min(dp[w][h][x], max(dp[w][h2][l], dp[w][h - h2][x - l]));
						}
					}
				}
			}
		}
	}

	int r, c, k;
	while (scanf("%d %d %d", &r, &c, &k) && r && c){

		printf("%d\n", dp[r][c][k]);
	}
}