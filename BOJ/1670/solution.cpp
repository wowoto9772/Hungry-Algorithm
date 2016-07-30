#include <stdio.h>
#define ll long long
#define mod 987654321

ll dp[10003];

int main(){

	dp[0] = 1;
	dp[2] = 1;

	int n;
	scanf("%d", &n);

	for (int i = 4; i <= n; i += 2){
		for (int j = 0; j < i; j += 2){
			ll g = dp[2] * dp[j];
			g %= mod;
			g *= dp[i - 2 - j];
			g %= mod;
			dp[i] += g;
			dp[i] %= mod;
		}
	}

	dp[0] = 0;

	printf("%lld\n", dp[n]);

}