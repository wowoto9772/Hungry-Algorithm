//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//#define MIN -1000000007
//
//int I[53];
//int dp[53][53];
//int M(int a, int b){ return a < b ? b : a; }
//
//
//int dy(int a, int b){
//	if (dp[a][b] != MIN)return dp[a][b];
//	return dp[a][b] = M(I[a] - dy(a + 1, b), I[b] - dy(a, b - 1));
//}
//
//int main(){
//	freopen("large_dat1.in", "r", stdin);
//	freopen("large_dat1.out", "w", stdout);
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		for (int i = 1; i <= n; i++)scanf("%d", &I[i]);
//
//		for (int i = 1; i <= n; i++){
//			dp[i][i] = I[i];
//			for (int j = i+1; j <= n; j++){
//				dp[i][j] = MIN;
//			}
//		}
//		printf("%d\n", dy(1, n));
//	}
//}