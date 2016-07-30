#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[103][103];
bool c[103][103];

int main() {

	int n;
	scanf("%d", &n);

	while (n--) {

		int x, y;
		scanf("%d %d", &x, &y);

		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				c[i][j] = true;
			}
		}

	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + c[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int a = i; a <= 100; a++) {
				for (int b = j; b <= 100; b++) {
					int s = (a - i + 1)*(b - j + 1);
					int cmp = dp[a][b] - dp[i - 1][b] - dp[a][j - 1] + dp[i - 1][j - 1];
					if (cmp == s)ans = max(ans, cmp);
					else
						break;
				}
			}
		}
	}

	printf("%d\n", ans);

}