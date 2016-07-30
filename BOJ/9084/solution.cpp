#include <stdio.h>

int dp[10003];
int c[23];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)scanf("%d", &c[i]);

		int m;
		scanf("%d", &m);

		for (int i = 1; i <= m; i++)dp[i] = 0;
		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m - c[i]; j++) {
				dp[j + c[i]] += dp[j];
			}
		}

		printf("%d\n", dp[m]);

	}

}