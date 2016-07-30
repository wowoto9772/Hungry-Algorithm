#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define ll long long

using namespace std;

ll dp[503][503];
int x[503], y[503];

ll dy(int c, int k) {

	if (c == 1) {
		if (!k)return 0;
		else
			return INT_MAX;
	}
	if (dp[c][k] != -1)return dp[c][k];

	dp[c][k] = INT_MAX;

	for (int i = c - 1; i >= c - 1 - k && i >= 1; i--) {
		dp[c][k] = min(dp[c][k], dy(i, k - ((c - 1) - i)) + abs(x[c] - x[i]) + abs(y[c] - y[i]));
	}

	return dp[c][k];
}

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		for (int j = 0; j <= k; j++)dp[i][j] = -1;
	}

	printf("%d\n", dy(n, k));

}