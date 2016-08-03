#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[2003][2];
int e[2003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &e[i]);

	}

	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {

		dp[i][1] = dp[i][0] = 1;

		// position i to n-1
		// 0 : increasing
		// 1 : decreasing

		for (int j = i + 1; j < n; j++) {
			if (e[j] < e[i])dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			if (e[j] > e[i])dp[i][0] = max(dp[i][0], dp[j][0] + 1);
		}

		ans = max(ans, dp[i][0] + dp[i][1] - 1);

	}

	printf("%d\n", ans);

}