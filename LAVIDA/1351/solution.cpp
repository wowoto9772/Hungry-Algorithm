//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//
//long long dp[53][53];
//char str[53][53];
//bool chk[53][53];
//
//int R, C;
//int dr[4] = { -1, 1, 0, 0 };
//int dc[4] = { 0, 0, -1, 1 };
//
//long long M(long long a, long long b){ return a < b ? b : a; }
//
//long long dy(int r, int c){
//	if (dp[r][c] != -1)return dp[r][c];
//
//	chk[r][c] = true;
//
//	int a = str[r][c] - '0';
//	dp[r][c] = 0;
//
//	for (int i = 0; i < 4; i++){
//		int nr = r + a * dr[i];
//		int nc = c + a * dc[i];
//		if (0 <= nr && nr < R){
//			if (0 <= nc && nc < C){
//				int w = str[nr][nc];
//				if ('1' <= w && w <= '9'){
//					if (chk[nr][nc]){
//						dp[r][c] = INT_MAX;
//						break;
//					}
//					else{
//						dp[r][c] = M(dp[r][c], dy(nr, nc) + 1);
//					}
//				}
//			}
//		}
//	}
//	
//	if (!dp[r][c])dp[r][c] = 1;
//
//	chk[r][c] = false;
//
//	return dp[r][c];
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		scanf("%d %d", &R, &C);
//		
//		for (int i = 0; i < R; i++)scanf("%s", str[i]);
//
//		memset(dp, 0xff, sizeof(dp));
//
//		long long ans = dy(0, 0);
//
//		if (ans >= INT_MAX)ans = -1;
//
//		printf("%lld\n", ans);
//	}
//}

#include <stdio.h>
#include <memory.h>
#define max(a,b) a < b ? b : a
int dp[53][53];
char str[53][53];

int R, C;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
bool cyc[53][53];

int dy(int r, int c){
	if (dp[r][c] != -1)return dp[r][c];

	int a = str[r][c] - '0';
	cyc[r][c] = true;
	dp[r][c] = 0;

	for (int i = 0; i < 4; i++){
		int nr = r + a * dr[i];
		int nc = c + a * dc[i];
		if (0 <= nr && nr < R){
			if (0 <= nc && nc < C){
				int w = str[nr][nc];
				if ('1' <= w && w <= '9'){
					if (cyc[nr][nc]){ // visited node
						dp[r][c] = 2503;
						break;
					}
					else{
						dp[r][c] = max(dp[r][c], dy(nr, nc) + 1);
					}
				}
			}
		}
	}

	cyc[r][c] = false;
	return dp[r][c];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++)scanf("%s", str[i]);

		memset(dp, 0xff, sizeof(dp));

		int ans = dy(0, 0);

		if (ans >= 2500)ans = -1;
		else
			ans++;

		printf("%d\n", ans);
	}
}