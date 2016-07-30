#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

double p[5003];
int w[5003];
int dp[5003];

int main() {

	int n;
	scanf("%d", &n);

	int tot = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		tot += w[i];
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		dp[i] = w[i];
		for (int j = i - 1; j >= 1; j--) {
			if (p[j] <= p[i]) { // lis + greedy
				dp[i] = max(dp[i], dp[j] + w[i]);
			}
		}
		ans = min(ans, tot - dp[i]);
	}

	printf("%d\n", ans);

}