#include <stdio.h>
#include <limits.h>

int dp[1000003][4];

int k[] = { 0, 3, 5, 8 };

int main() {

	dp[1][0] = dp[2][0] = INT_MAX;

	for (int i = 3; i <= 1000000; i++) {

		dp[i][0] = INT_MAX;

		for (int i2 = 1; i2 <= 3; i2++) {

			int j = i - k[i2];

			if (j < 0)break;

			if (dp[j][0] != INT_MAX) {

				if (dp[i][0] > dp[j][0] + 1) {

					dp[i][0] = dp[j][0] + 1;

					for (int a = 1; a <= 3; a++)dp[i][a] = dp[j][a];

					dp[i][i2]++;

				}
				else if (dp[i][0] == dp[j][0] + 1) {

					int p = i2 == 1;
					if (dp[i][1] < dp[j][1] + p) {

						dp[i][1] = dp[j][1] + p;
						dp[i][2] = dp[j][2];
						dp[i][3] = dp[j][3];
						dp[i][0]++;

					}
					else if (dp[i][1] == dp[j][1] + p) {

						p = i2 == 2;

						if (dp[i][2] < dp[j][2] + p) {

							dp[i][2] = dp[j][2] + p;
							dp[i][3] = dp[j][3];
							dp[i][0]++;

						}

					}

				}

			}

		}

	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		if (dp[n][0] == INT_MAX)printf("-1");
		else {
			for (int j = 1; j <= 3; j++) {
				for (int a = 1; a <= dp[n][j]; a++)printf("%d", k[j]);
			}
		}

		printf("\n");

	}

}