#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[503][503];
int a[503][503];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int n;

int dy(int i, int j) {

	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = 0;

	for (int k = 0; k < 4; k++) {
		int ni = i + dr[k];
		int nj = j + dc[k];

		if (ni < 1 || nj < 1 || ni > n || nj > n)continue;

		if (a[i][j] < a[ni][nj]) {
			dp[i][j] = max(dp[i][j], 1 + dy(ni, nj));
		}
	}

	return dp[i][j];

}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j] = -1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, dy(i, j));
		}
	}

	printf("%d\n", ++ans);

}