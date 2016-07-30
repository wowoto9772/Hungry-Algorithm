#include <stdio.h>

int dp[10003][5];
int b[] = { 0, 1, 5, 10, 25 };

int main() {

	int x, a[5];

	scanf("%d", &x);

	for (int i = 1; i <= x; i++) {
		dp[i][0] = -1;
	}

	for (int i = 1; i <= 4; i++)scanf("%d", &a[i]);

	for (int i = 1; i <= 4; i++) {

		if (!a[i])continue;

		for (int j = x - b[i]; j >= 0; j--) {
			if (dp[j][0] != -1) {
				for (int k = a[i]; k >= 1; k--) {
					if (j + k*b[i] <= x) {
						if (dp[j + k*b[i]][0] < dp[j][0] + k) {
							dp[j + k*b[i]][0] = dp[j][0] + k;
							for (int l = 1; l <= 4; l++)dp[j + k*b[i]][l] = dp[j][l];
							dp[j + k*b[i]][i] += k;
						}
					}
				}
			}
		}
	}

	if (dp[x][0] == -1)printf("0 0 0 0\n");
	else {
		printf("%d %d %d %d\n", dp[x][1], dp[x][2], dp[x][3], dp[x][4]);
	}

}