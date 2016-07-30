#include <stdio.h>
#define mod 1000000007;

long long dp[1003][3];

int main(){
	dp[1][0] = 1, dp[1][1] = 1;
	for (int i = 2; i <= 1000; i++){
		dp[i][0] = (dp[i-1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][1];
	}

	int t;
	while (scanf("%d", &t) == 1){

		while (t--){
			int n;
			scanf("%d", &n);

			long long a = dp[n][0] + dp[n][1] + dp[n][2];
			a %= mod;

			printf("%lld\n", a);
		}

	}
}