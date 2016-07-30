#include <stdio.h>
#include <limits.h>

int f[8] = { 0, 1 };
int dp[10003] = { 0, 1 };
int m(int a, int b){ return a < b ? a : b; }

int main(){
	for (int i = 2; i <= 7; i++){
		f[i] = f[i-1] * i;
		dp[f[i]] = i;
	}

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++){
		if (!dp[i])dp[i] = INT_MAX;
		for (int j = 1; j < i; j++){
			if (j <= 7 && f[j] == i)dp[i] = dp[j];
			dp[i] = m(dp[i], dp[j] + dp[i - j]); // sum
			if (j > 1 && !(i%j))dp[i] = m(dp[i], dp[i / j] + dp[j]); // time
		}
	}

	printf("%d\n", dp[n]);
}