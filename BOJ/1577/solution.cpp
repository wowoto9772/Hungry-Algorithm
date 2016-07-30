#include <stdio.h>
#define ll long long

bool chk[103][103][2]; // - |
ll dp[103][103];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	dp[0][0] = 1;

	int q;
	scanf("%d", &q);

	for (int i = 1; i <= q; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == c) {
			if (b > d) {
				int k = b;
				b = d;
				d = k;
			}
			for (int j = b; j < d; j++) {
				chk[a][j][0] = true;
			}
		}
		else {
			// b == d
			if (a > c) {
				int k = a;
				a = c;
				c = k;
			}
			for (int j = a; j < c; j++) {
				chk[j][b][1] = true;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!(i | j))continue;
			if (j) {
				if (!chk[i][j - 1][0]) {
					dp[i][j] += dp[i][j - 1];
				}
			}
			if (i) {
				if (!chk[i - 1][j][1]) {
					dp[i][j] += dp[i - 1][j];
				}
			}
		}
	}

	printf("%lld\n", dp[n][m]);

}