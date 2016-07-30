#include <stdio.h>
#define mod 1000000003

int dp[1003][1003][2];
int n, k;

// a-th color, selected b colors, can select last color
int dy(int a, int b, bool can) {
	if (b == k)return 1;
	if (a >= n - can)return 0;

	if (dp[a][b][can] != -1)return dp[a][b][can];

	dp[a][b][can] = 0;

	dp[a][b][can] += dy(a + 2, b + 1, can); // select
	dp[a][b][can] += dy(a + 1, b, can); // do not select

	return dp[a][b][can] %= mod;
}

int main() {

	scanf("%d %d", &n, &k);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int k = 0; k <= 1; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	// 0 to n-1 color
	printf("%d\n", (dy(1, 0, false) + dy(2, 1, true)) % mod);

}