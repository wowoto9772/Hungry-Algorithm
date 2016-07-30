#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		bool dp[103] = { 0 };

		int n;
		scanf("%d", &n);

		for (int i = 2; i <= n; i++) {
			for (int k = i; k <= n; k += i) {
				dp[k] ^= true;
			}
		}

		int c = 0;
		for (int i = 1; i <= n; i++)if (!dp[i])c++;

		printf("%d\n", c);

	}

}