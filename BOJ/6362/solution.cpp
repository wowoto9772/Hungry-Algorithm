#include <stdio.h>
#define N 300

#define ll long long

ll dp[N + 2][N + 2];

ll dy(int v, int l) {
	if (!v)return 1;
	if (dp[v][l] != -1)return dp[v][l];

	dp[v][l] = 0;

	for (int i = v / 2; i >= 1; i--) {
		if (l >= i) {
			dp[v][l] += dy(v - i * 2, i);
		}
	}

	return dp[v][l];

}

int main() {

	int n;
	while (scanf("%d", &n) == 1 && n) {

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = -1;
			}
		}

		ll ans = 0;

		for (int i = 1; i <= n; i++) {
			ans += dy(n - i, i);
		}

		ans += dy(n, n);

		printf("%d %lld\n", n, ans);

	}

}