#include <stdio.h>

#define mod 100999

int dp[2003] = { 1, };

int main() {

	int n = 2000;
	
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j >= 0; j--) {
			dp[j+i] += dp[j];
			dp[j + i] %= mod;
		}
	}

	scanf("%d", &n);

	while (n--) {

		int v;
		scanf("%d", &v);

		printf("%d\n", dp[v]);

	}

}