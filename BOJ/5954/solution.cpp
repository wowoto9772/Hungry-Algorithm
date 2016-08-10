#include <stdio.h>
#define mod 1000000

int dp[500003][2];

int main() {

	int n;
	scanf("%d", &n);

	

	int tot = 0;
	int MV = 0;

	for (int i = 1; i <= 2500; i++)dp[i][0] = dp[i][1] = -1;
	
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {

		int e;
		scanf("%d", &e);

		tot += e;

		int p = 0, c = 1;

		for (int j = 0; j <= MV; j++) {

			if (dp[j][p] != -1) {
				if (dp[j][c] == -1)dp[j][c] = dp[j][p];
				else {
					dp[j][c] += dp[j][p];
					dp[j][c] %= mod;
				}
				if (dp[j + e][c] == -1)dp[j + e][c] = dp[j][p];
				else {
					dp[j + e][c] += dp[j][p];
					dp[j + e][c] %= mod;
				}
			}

		}

		MV += e;

		for (int j = 0; j <= MV; j++) {

			if(j <= MV)dp[j][p] = dp[j][c];
			if(i != n)dp[j][c] = -1;

		}

	}

	for (int i = tot>>1; i >= 1; i--) {
		if (dp[i][1] >= 0) {
			printf("%d\n%d\n", (tot-(i<<1)), dp[i][1]);
			break;
		}
	}

}