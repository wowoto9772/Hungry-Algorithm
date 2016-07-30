#include <stdio.h>
#include <memory.h>
#define mod 1000000000

int dp[203][203];

int dy(int s, int k){
	if (!k){
		if(!s)return 1;
		return 0;
	}

	if (dp[s][k] != -1)return dp[s][k];

	dp[s][k] = 0;
	for (int i = s; i >= 0; i--){
		dp[s][k] += dy(s - i, k - 1);
		dp[s][k] %= mod;
	}

	return dp[s][k];

}

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(n, k));

}