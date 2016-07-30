#include <stdio.h>
#include <memory.h>
#include <limits.h>

int M[22];
int dp[22][22][22];

int min(int a, int b){ return a < b ? a : b; }
int A(int a){ return a < -a ? -a : a; }

int main(){
	int n;
	scanf("%d", &n);

	int l, r;
	scanf("%d %d", &l, &r);

	int m;
	scanf("%d", &m);

	for (int i = 1; i <= m; i++){
		scanf("%d", &M[i]);
	}

	if (!m)printf("0\n");
	else{
		for (int k = 0; k <= m; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					dp[k][i][j] = 1011111111;
				}
			}
		}

		dp[0][l][r] = 0;
		int ans = INT_MAX;
		for (int k = 1; k <= m; k++){
			for (int i = 1; i < n; i++){
				for (int j = 1; j <= n; j++){
					if (i == j)continue;
					int cost = A(j - M[k]);
					dp[k][i][M[k]] = min(dp[k][i][M[k]], dp[k - 1][i][j] + cost);
					cost = A(i - M[k]);
					dp[k][M[k]][j] = min(dp[k][M[k]][j], dp[k - 1][i][j] + cost);
					if (k == m){
						ans = min(ans, dp[k][i][M[k]]);
						ans = min(ans, dp[k][M[k]][j]);
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}

//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//
//int dp[22][22][22];
//int M[22];
//int n, m;
//int A(int a){ return a < -a ? -a : a; }
//int min(int a, int b){ return a < b ? a : b; }
//
//int dy(int l, int r, int k){
//	if (k == m + 1)return 0;
//	if (dp[l][r][k] != -1)return dp[l][r][k];
//	
//	dp[l][r][k] = INT_MAX;
//
//	for (int i = 1; i < n; i++){
//		for (int j = i + 1; j <= n; j++){
//			if (i == M[k] || j == M[k]){
//				int cst = A(i - l) + A(j - r);
//				dp[l][r][k] = min(dp[l][r][k], cst + dy(i, j, k + 1));
//			}
//		}
//	}
//
//	return dp[l][r][k];
//}
//
//int main(){
//	scanf("%d", &n);
//	
//	int l, r;
//	scanf("%d %d", &l, &r);
//
//	scanf("%d", &m);
//
//	for (int i = 1; i <= m; i++){
//		scanf("%d", &M[i]);
//	}
//
//	memset(dp, 0xff, sizeof(dp));
//
//	printf("%d\n", dy(l, r, 1));
//}