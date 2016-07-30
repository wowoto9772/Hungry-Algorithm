////#include <stdio.h>
////#include <memory.h>
////
////#define mod 8888577
////
////int dp[503][1 << 7][1 << 7];
////
////int R, C;
////int x;
////
////int dy(int i, int c, int n){ // i th current and next state
////	if (i == C && !c)return 1;
////
////	if (dp[i][c][n] != -1)return dp[i][c][n];
////
////	dp[i][c][n] = 0;
////
////	if (c == (1 << R) - 1){
////		int rx = x;
////		x = 0;
////		dp[i][c][n] = dy(i + 1, n, 0);
////		x = rx;
////	}
////	else{
////		int y = 0;
////		while (x < R){
////			int k = (1 << x);
////			if (!(k & c)){
////				if (x < R - 1){ // 2*1 block [][]
////					if (!(k << 1 & c)){
////						x += 2;
////						dp[i][c][n] = (dp[i][c][n] + dy(i, c | k * 3, n)) % mod;
////						x -= 2;
////					}
////				}
////				if (i < C - 1){ // 1*2 block
////					if (!(k & n)){
////						x++;
////						dp[i][c][n] = (dp[i][c][n] + dy(i, c | k, n | k)) % mod;
////						x--;
////					}
////				}
////				break;
////			}
////			else{
////				x++;
////				y++;
////			}
////		}
////		x -= y;
////	}
////
////	return dp[i][c][n];
////}
////
////int main(){
////	int t;
////	scanf("%d", &t);
////	while (t--){
////
////		scanf("%d %d", &R, &C);
////
////		if (R > C){
////			int l = R;
////			R = C;
////			C = l;
////		}
////
////		memset(dp, 0xff, sizeof(dp));
////		x = 0;
////
////		if (R % 2 && C % 2)printf("0\n");
////		else{
////			printf("%d\n", dy(0, 0, 0));
////		}
////	}
////}
////
////// 7 * 500 size but, 500 * 7
//
//
//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//#define MOD 8888577
//
//int h, w;
//
//int dp[1 << 7][500][7];
//
//int dy(int n, int i, int j){
//	if (i >= h)return 1;
//	if (j >= w){
//		return dy(n, i + 1, 0);
//	}
//	if (dp[n][i][j] != -1)return dp[n][i][j];
//
//	dp[n][i][j] = 0;
//
//	int n_ = (n >> 1);
//	if (n & 1){
//		return dp[n][i][j] = dy(n_, i, j + 1);
//	}
//
//	if (i < h-1){
//		dp[n][i][j] += dy(n_ | (1 << (w - 1)), i, j + 1);
//		dp[n][i][j] %= MOD;
//	}
//
//	if (j < w-1 && !(n_ & 1)){
//		n_ = n >> 2;
//		dp[n][i][j] += dy(n_, i, j + 2);
//		dp[n][i][j] %= MOD;
//	}
//
//	return dp[n][i][j];
//}
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		scanf("%d %d", &h, &w);
//		if (h % 2 && w % 2)printf("0\n");
//		else{
//			memset(dp, 0xff, sizeof(dp));
//			printf("%d\n", dy(0, 0, 0));
//		}
//	}
//}

#include <stdio.h>

#define mod 8888577
#define H 500
#define W 7

int d[H*W + 1][1 << W] = { 0 };
int dp[H + 1][W + 1];

int main()
{
	int h, w;

	h = 500;

	for (w = 1; w <= 7; w++) {

		// init
		for (int i = 0; i < h*w; i++)for (int j = 0; j < (1 << w); j++)d[i][j] = 0;

		d[0][0] = 1;
		d[w*h][0] = 0;

		for (int x = 0; x < h*w; x++)
		{
			for (int i = 0; i < (1 << w); i++)
			{
				if (i & 1) {
					
					// block exists

					d[x + 1][i >> 1] += d[x][i];
					d[x + 1][i >> 1] %= mod;

				}
				else
				{
					if (!(i & 3) && (x%w != w - 1)) {
						d[x + 2][(i >> 2)] += d[x][i];
						d[x + 2][(i >> 2)] %= mod;
					}
					d[x + 1][(i >> 1) | (1 << (w - 1))] += d[x][i];
					d[x + 1][(i >> 1) | (1 << (w - 1))] %= mod;
				}
			}
		}

		for (int i = 1; i <= h; i++)dp[i][w] = d[w*i][0];

	}

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d %d", &w, &h);

		if (w < 0 || h < 0)break;

		printf("%d\n", dp[w][h]);

	}

	return 0;
}