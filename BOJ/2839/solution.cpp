#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[5003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)dp[i] = INT_MAX;

	for (int i = 3; i <= n; i++) {
		if (dp[i - 3] != INT_MAX)dp[i] = min(dp[i], dp[i - 3] + 1);
		if (i >= 5 && dp[i - 5] != INT_MAX)dp[i] = min(dp[i], dp[i - 5] + 1);
	}

	if (dp[n] == INT_MAX)dp[n] = -1;
	printf("%d\n", dp[n]);

}