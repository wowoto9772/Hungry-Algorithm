#include <stdio.h>
#include <limits.h>
#include <memory.h>

int dp[1 << 20][21];
int x[21], y[21], N;
int A(int a){ return a < -a ? -a : a; }
int D(int a, int b){
	return A(x[a] - x[b]) + A(y[a] - y[b]);
}
int m(int a, int b){ return a > b ? b : a; }

int dy(int c, int n){
	if (dp[c][n] != -1)return dp[c][n];

	dp[c][n] = INT_MAX;

	for (int i = 1; i <= N; i++){
		if (c&(1 << (i-1)))continue;
		dp[c][n] = m(dp[c][n], dy(c | (1 << (i-1)), i) + D(n, i));
	}

	return dp[c][n];
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d %d", &N, &x, &y);

		memset(dp, 0xff, sizeof(dp));

		for (int i = 1; i <= N; i++){
			scanf("%d %d", &x[i], &y[i]);
			dp[(1 << N) - 1][i] = 0;
		}

		printf("%d\n", dy(0, 0));
	}
}