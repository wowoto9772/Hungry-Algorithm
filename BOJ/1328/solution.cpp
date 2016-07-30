#include <stdio.h>
#include <memory.h>

#define mod 1000000007LL

long long dp[103][103][103];

long long dy(long long n, int l, int r){
	if (n < 0)return 0;
	if (dp[n][l][r] != -1)return dp[n][l][r];

	dp[n][l][r] = 0;
	if (l)dp[n][l][r] += dy(n - 1, l - 1, r); // leftmost
	if (r)dp[n][l][r] += dy(n - 1, l, r - 1); // rightmost
	if (n > 2){
		dp[n][l][r] += dy(n - 1, l, r) * (n - 2); // in the middle
	}

	dp[n][l][r] %= mod;
	return dp[n][l][r];
} // tall to short

int main(){

	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);

	memset(dp, 0xff, sizeof(dp));

	for (int i = 1; i <= l; i++){
		dp[i][i][1] = 1LL;
	}

	for (int i = 1; i <= r; i++){
		dp[i][1][i] = 1LL;
	}

	printf("%lld\n", dy(n, l, r));
}