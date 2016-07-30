#include <stdio.h>
#include <memory.h>

int dp[2002][2002];
int	L[2002], R[2002];
int M(int a, int b){ return a < b ? b : a; }

int dy(int l, int r){
	// #3
	if (!l || !r)return 0;

	if (dp[l][r] != -1)return dp[l][r];

	dp[l][r] = 0;

	// #1
	dp[l][r] = M(dp[l][r], M(dy(l - 1, r - 1), dy(l - 1, r)));

	// #2
	if (L[l] > R[r]){
		dp[l][r] = M(dp[l][r], R[r] + dy(l, r - 1));
	}

	return dp[l][r];
}

int main(){
	int N;
	scanf("%d", &N);

	for (int i = N; i >= 1; i--)scanf("%d", &L[i]);
	for (int i = N; i >= 1; i--)scanf("%d", &R[i]);

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(N, N));
}