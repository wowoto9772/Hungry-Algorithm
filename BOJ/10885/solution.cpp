//#include <stdio.h>
//
//#define mod 1000000007
//
//int M(int a, int b){ return a < b ? b : a; }
//int m(int a, int b){ return a < b ? a : b; }
//
//int dp[100003][2];
//
///*
//	0 : - maximum
//	1 : + maximum
//*/
//
//int main(){
//
//	dp[0][0] = dp[0][1] = 1;
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		scanf("%d", &n);
//
//		dp[n][1] = 0;
//
//		int a;
//		bool zero = false;
//		for (int i = 1; i <= n; i++){ // subsequence max
//			scanf("%d", &a);
//			if (!a)zero = true;
//			else{
//				if (a > 0){
//					dp[i][1] = (dp[i - 1][1] * a) % mod;
//					dp[i][0] = (dp[i - 1][0] * a) % mod;
//				}
//				else{
//					dp[i][1] = M(dp[i - 1][0] * a, dp[i - 1][1]) % mod;
//					dp[i][0] = m(dp[i - 1][1] * a, dp[i-1][0]) % mod;
//				}
//			}
//		}
//
//		printf("%d\n", dp[n][1]);
//	}/
//}

#include <stdio.h>

#define mod 1000000007

int M(int a, int b){ return a < b ? b : a; }
int m(int a, int b){ return a < b ? a : b; }

int main(){
	dp[0][0] = dp[0][1] = 1;

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int ans = 0;

		int a;
		bool zero = false;
		for (int i = 1; i <= n; i++){ // subsequence max
			scanf("%d", &a);
			if (!a){
				ans = M(ans, dp[i - 1][0]);
				zero = true;
				dp[i][0] = dp[i][1] = 1;
			}
			else{
				if (a > 0){
					dp[i][1] = (dp[i - 1][1] * a) % mod;
					dp[i][0] = (dp[i - 1][0] * a) % mod;
				}
				else{
					dp[i][1] = (dp[i - 1][0] * a) % mod;
					dp[i][0] = (dp[i - 1][1] * a) % mod;
				}
			}
		}

		printf("%d\n", dp[n][1]);
	}
}