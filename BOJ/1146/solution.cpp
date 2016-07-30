#include <stdio.h>
#include <memory.h>

#define mod 1000000

int dp[103][103][2];

int dy(int lo, int hi, int big){
	if (!lo && !hi)return 1;

	if (dp[lo][hi][big] != -1)return dp[lo][hi][big];

	dp[lo][hi][big] = 0;

	if (!big){
		for (int i = 1; i <= hi; i++){
			dp[lo][hi][big] += dy(lo + i - 1, hi - i, 1);
			dp[lo][hi][big] %= mod;
		}
	} else{
		for (int i = 1; i <= lo; i++){
			dp[lo][hi][big] += dy(lo - i, hi + i - 1, 0);
			dp[lo][hi][big] %= mod;
		}
	}

	return dp[lo][hi][big];
}

int main(){
	int n;
	scanf("%d", &n);

	memset(dp, 0xff, sizeof(dp));

	int ans = 0;
	if (n == 1)ans = 1;
	else if (n == 2)ans = 2;
	else{
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j)continue;
				if (i < j)ans += dy(j - 2, n - j, 1); 
				else{
					ans += dy(j - 1, n - j - 1, 0);
				}
				ans %= mod;
			}
		}
	}

	printf("%d\n", ans);
}