#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define ll long long

using namespace std;

int x[100003], y[100003];

int dr[] = { 0, 0, 0, -1, 1 };
int dc[] = { 0, -1, 1, 0, 0 };

ll dp[100003][5];

int main() {

	int n;
	scanf("%d", &n);

	dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
	for (int i = 0; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (i)dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4] = LLONG_MAX;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			int nx = x[i] + dr[j];
			int ny = y[i] + dc[j];
			for (int k = 0; k <= 4; k++) {
				int cx = x[i - 1] + dr[k];
				int cy = y[i - 1] + dc[k];
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(nx - cx) + abs(ny - cy));
			}
		}
	}

	printf("%lld\n", min(dp[n][0], min(dp[n][1], min(dp[n][2], min(dp[n][3], dp[n][4])))));
}