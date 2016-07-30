#include <stdio.h>
#include <memory.h>

int I[103];
int N[103];
int J[103][13];
int dp[10003][103];
int n, m;

int M(int a, int b){ return a < b ? b : a; }
int dy(int w, int i){
	if (i > n)return 0;
	if (dp[w][i] != -1)return dp[w][i];

	dp[w][i] = 0;

	for (int j = N[i]; j >= 0; j--){
		int cst = j*I[i];
		if (w + cst <= m){
			dp[w][i] = M(dp[w][i], dy(w + cst, i + 1) + J[i][j]);
		}
	}

	return dp[w][i];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &I[i]);
		scanf("%d", &N[i]);
		for (int j = 1; j <= N[i]; j++){
			scanf("%d", &J[i][j]);
			J[i][j] += J[i][j - 1];
		}
	}

	memset(dp, 0xff, sizeof(dp));
	printf("%d\n", dy(0, 1));
}


//#include <stdio.h>
//#include <memory.h>
//
//int dp[10003], dp2[10003];
//int I[103], N[103], C[103][13];
//int M(int a, int b){ return a < b ? b : a; }
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &I[i]);
//		scanf("%d", &N[i]);
//		for (int j = 1; j <= N[i]; j++){
//			scanf("%d", &C[i][j]);
//			C[i][j] += C[i][j - 1];
//		}
//	}
//
//	int c = 0;
//	int ans = 0;
//	for (int i = 1; i <= n; i++){
//		c ^= 1;
//		if (c == 1){
//			memset(dp2, 0, sizeof(dp2));
//		}
//		else{
//			memset(dp, 0, sizeof(dp));
//		}
//		for (int j = 0; j <= m; j++){
//			if (c == 1){
//				for (int k = 0; k <= N[i]; k++){
//					int nxt = j + I[i] * k;
//					if (nxt <= m){
//						dp2[nxt] = M(dp2[nxt], dp[j] + C[i][k]);
//						ans = ans < dp2[nxt] ? dp2[nxt] : ans;
//					}
//					else{
//						break;
//					}
//				}
//			}
//			else{
//				for (int k = 0; k <= N[i]; k++){
//					int nxt = j + I[i] * k;
//					if (nxt <= m){
//						dp[nxt] = M(dp[nxt], dp2[j] + C[i][k]);
//						ans = ans < dp[nxt] ? dp[nxt] : ans;
//					}
//					else{
//						break;
//					}
//				}
//			}
//		}
//		if (c == 1){
//			for (int j = 1; j <= m; j++)dp[j] = dp2[j];
//		}
//		else{
//			for (int j = 1; j <= m; j++)dp2[j] = dp[j];
//		}
//	}
//
//	printf("%d\n", ans);
//}

/*
	3 170
	50 3 10 5 7
	70 1 20
	50 2 9 8

	2 100
	100 1 50
	50 2 10 10

	1 150
	50 3 5 9 13
	
	1 3
	1 3 3 4 7
*/