#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[2][1003];
int a[1003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[0][i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])dp[0][i] = max(dp[0][i], dp[0][j] + 1);
		}
	}

	for (int i = n; i >= 1; i--) {
		dp[1][i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j])dp[1][i] = max(dp[1][i], dp[1][j] + 1);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[0][i] + dp[1][i] - 1);
	}

	printf("%d\n", ans);

}