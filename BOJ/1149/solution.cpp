#include <stdio.h>
#include <algorithm>

using namespace std;

int c[1003][3];
int dp[1003][3];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 3; j++)scanf("%d", &c[i][j]);
	}

	for (int i = 1; i <= n; i++){
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + c[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + c[i][2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + c[i][0];
	}

	printf("%d\n", min(dp[n][1], min(dp[n][0], dp[n][2])));
}