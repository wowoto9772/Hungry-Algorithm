#include <stdio.h>
#define Max 359 * 360

bool dp[Max + 3];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	dp[0] = true;

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);

		for (int j = 0; j + a <= Max; j++) {
			if (dp[j]) {
				dp[j + a] = true;
			}
		}
		for (int j = Max; j - a >= 0; j--) {
			if (dp[j]) {
				dp[j - a] = true;
			}
		}

	}

	bool chk[363] = { 0 };
	for (int i = 0; i <= Max; i++) {
		if (dp[i])chk[i % 360] = true;
	}

	for (int i = 1; i <= k; i++) {
		int a;
		scanf("%d", &a);
		printf("%s\n", chk[a] ? "YES" : "NO");
	}

}