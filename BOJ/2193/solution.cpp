#include <stdio.h>
#define ll long long

ll dp[93][2];
int n;

ll dy(int c, int m) {
	if (c == n)return 1;
	if (dp[c][m] != -1)return dp[c][m];

	dp[c][m] = 0;

	dp[c][m] = dy(c + 1, 0);
	if (!m)dp[c][m] += dy(c + 1, 1);

	return dp[c][m];
}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)for (int k = 0; k <= 1; k++)dp[i][k] = -1;

	printf("%lld\n", dy(1, 1));

}