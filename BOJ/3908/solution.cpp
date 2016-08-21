#include <stdio.h>

int P[203], top;
bool p[1123];

int dp[1123][15];

int main() {

	for (int i = 2; i*i <= 1120; i++) {
		if (p[i])continue;
		for (int j = i*i; j <= 1120; j += i)p[j] = true;
	}

	for (int i = 2; i <= 1120; i++) {
		if (!p[i])P[top++] = i;
	}

	dp[0][0] = 1;

	for (int i = 0; i < top; i++) {
		for (int j = 1120 - P[i]; j >= 0; j--) {
			for (int k = 0; k < 14; k++) {
				dp[j + P[i]][k + 1] += dp[j][k];
			}
		}
	}

	int n;
	scanf("%d", &n);

	while (n--) {

		int v, k;
		scanf("%d %d", &v, &k);

		printf("%d\n", dp[v][k]);

	}

}