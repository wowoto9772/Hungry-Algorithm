#include <stdio.h>

int dp[33][33];
int L;

int dy(int n, int l){

	if (!n)return 1;
	else if (dp[n][l] != -1)return dp[n][l];

	if (l == L)dp[n][l] = 1;
	else{
		dp[n][l] = dy(n - 1, l + 1);
		dp[n][l] += dy(n - 1, l);
	}

	return dp[n][l];

}

int main(){

	int n;
	scanf("%d %d", &n, &L);

	printf("%d\n", dy(n-1, 0));

}