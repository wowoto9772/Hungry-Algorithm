////#include <stdio.h>
////#include <memory.h>
////
////#define mod 1000000007
////
////int dp[103][1 << 8][1 << 8];
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
////					if (!(k<<1 & c)){
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
////	while (scanf("%d %d", &R, &C) == 2 && R > 0 && C > 0){
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
////// 8 * 100 size but, 100 * 8
//
//#include <stdio.h>
//#include <memory.h>
//#define MOD 1000000007
//
//int h, w;
//
//int dp[1 << 8][100][8];
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
//	if (i < h - 1){
//		dp[n][i][j] += dy(n_ | (1 << (w - 1)), i, j + 1);
//		dp[n][i][j] %= MOD;
//	}
//
//	if (j < w - 1 && !(n_ & 1)){
//		n_ = n >> 2;
//		dp[n][i][j] += dy(n_, i, j + 2);
//		dp[n][i][j] %= MOD;
//	}
//
//	return dp[n][i][j];
//}
//int main()
//{
//	while (scanf("%d %d", &w, &h) == 2 && w > 0){
//
//		memset(dp, 0xff, sizeof(dp));
//
//		printf("%d\n", dy(0, 0, 0));
//	}
//}

#include<stdio.h>
#include<algorithm>

#define mod 1000000007
#define H 100
#define W 8

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