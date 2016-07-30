//#include <stdio.h>
//
//long long dp[22][22];
//long long c[22][22];
//long long f[22];
//
//int main(){
//	c[0][0] = 1;
//	f[0] = 1;
//	for (long long i = 1; i <= 20; i++){
//		f[i] = f[i - 1] * i;
//		c[i][0] = 1;
//		for (int j = 1; j <= i; j++){
//			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
//		}
//	}
//
//	dp[0][0] = 1;
//	for (long long i = 1; i <= 20; i++){
//		for (long long j = 1; j <= i; j++){
//			for (long long k = 0; k < i; k++){
//				dp[i][j] += dp[k][j - 1] * c[i - 1][k] * f[i - k - 1];
//			}
//		}
//	}
//
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, l, r;
//		scanf("%d %d %d", &n, &l, &r);
//
//		long long ans = 0;
//		for (int i = l; i <= n + 1 - r; i++){
//			ans += dp[i - 1][l - 1] * dp[n - (i - 1) - 1][r - 1] * c[n - 1][i - 1];
//		}
//
//		printf("%lld\n", ans);
//	}
//} // math

#include <stdio.h>
#include <memory.h>

long long dp[22][22][22];

long long dy(long long n, int l, int r){
	if (n < 0)return 0;
	if (dp[n][l][r] != -1)return dp[n][l][r];

	dp[n][l][r] = 0;
	if(l)dp[n][l][r] += dy(n - 1, l - 1, r); // leftmost
	if(r)dp[n][l][r] += dy(n - 1, l, r - 1); // rightmost
	if (n > 2){
		dp[n][l][r] += dy(n - 1, l, r) * (n - 2); // in the middle
	}

	return dp[n][l][r];
} // tall to short

int main(){
	memset(dp, 0xff, sizeof(dp));

	for (int i = 1; i <= 20; i++){
		dp[i][i][1] = 1LL;
		dp[i][1][i] = 1LL;
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int n, l, r;
		scanf("%d %d %d", &n, &l, &r);

		printf("%lld\n", dy(n, l, r));
	}
}