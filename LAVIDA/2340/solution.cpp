//#include <stdio.h>
//#include <memory.h>
//
//#include <algorithm>
//
//#define MAX 1000000007
//
//using namespace std;
//
//class ele{
//public:
//	int r, c;
//}I[103];
//
//int N, S;
//int dp[102][102];
//bool chk[102];
//
//int dy(int c, int k){
//	if (dp[c][k] != -1)return dp[c][k];
//
//	dp[c][k] = MAX;
//
//	for (int i = 1; i <= N; i++){
//		if (!chk[i] && I[c].c == I[i].r){
//			chk[i] = true;
//
//			dp[c][k] = min(dp[c][k], S*I[c].c*I[i].c + dy(i, k + 1));
//
//			chk[i] = false;
//		}
//	}
//
//	if (k == N && dp[c][k] == MAX)dp[c][k] = 0;
//
//	return dp[c][k];
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		scanf("%d", &N);
//
//		for (int i = 1; i <= N; i++){
//			scanf("%d %d", &I[i].r, &I[i].c);
//		}
//
//		memset(dp, 0xff, sizeof(dp));
//
//		int ans = MAX;
//
//		for (int i = 1; i <= N; i++){
//			S = i;
//			chk[i] = true;
//			ans = ans > dy(i, 1) ? dy(i, 1) : ans;
//			chk[i] = false;
//		}
//
//		printf("%d\n", ans);
//	}
//}

/* 아예 행렬을 내 맘대로 곱하는 줄 알았네 */

//#include <stdio.h>
//#include <memory.h>
//
//#define MAX 1000000007
//
//class ele{
//public:
//	int r, c;
//}I[103];
//
//int dp[102][102];
//
//int m(int a, int b){ return a < b ? a : b; }
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		memset(dp, 0x4f, sizeof(dp));
//
//		for (int i = 1; i <= n; i++){
//			scanf("%d %d", &I[i].r, &I[i].c);
//			dp[i][i] = 0;
//		}
//		
//		for (int a = 0; a < n; a++){
//			for (int i = 1; i <= n; i++){
//				int j = i + a;
//				if (j > n)break;
//				if (dp[i][j] >= MAX)continue;
//
//				int k = j + 1;
//				for (int b = 0; b <= a; b++){
//					int l = k + b;
//					if (l > n)break;
//					if(dp[k][l] >= MAX)continue;
//					if (I[j].c == I[k].r){
//						int x = I[i].r * I[j].c * I[l].c;
//						dp[i][l] = m(dp[i][l], dp[i][j] + dp[k][l] + x);
//					}
//				}
//			}
//		}
//
//		int ans = dp[1][n];
//
//		if (ans >= MAX)ans = -1;
//
//		printf("%d\n", ans);
//	}
//}

#include <stdio.h>
#include <memory.h>

#define MAX 1000000007

class ele{
public:
	int r, c;
}I[103];

int dp[102][102];

int m(int a, int b){ return a < b ? a : b; }

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		memset(dp, 0x4f, sizeof(dp));

		for (int i = 1; i <= n; i++){
			scanf("%d %d", &I[i].r, &I[i].c);
			dp[i][i] = 0;
		}

		for (int a = 1; a < n; a++){
			for (int i = 1; i <= n; i++){
				int k = i + a;
				if (k > n)break;
				for (int j = i; j < k; j++){
					if (I[j].c == I[j + 1].r){
						int x = I[i].r * I[j].c * I[k].c;
						dp[i][k] = m(dp[i][k], dp[i][j] + dp[j+1][k] + x);
					}
				}
			}
		}

		int ans = dp[1][n];

		if (ans >= MAX)ans = -1;

		printf("%d\n", ans);
	}
}