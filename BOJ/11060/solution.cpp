#include <stdio.h>
#include <algorithm>

using namespace std;

int s[1003];

int dp[1003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		dp[i] = -1;
	}

	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] > -1 && j + s[j] >= i) {
				if (dp[i] == -1)dp[i] = dp[j] + 1;
				else
					dp[i] = min(dp[j] + 1, dp[i]);
			}
		}
	}

	printf("%d\n", dp[n - 1]);

}