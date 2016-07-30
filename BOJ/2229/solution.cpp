#include <stdio.h>
#include <algorithm>

using namespace std;

int e[1003];
int dp[1003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &e[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int j = i - 1; j >= 1; j--) {
			int M = 0, m = 10003;
			for (int k = j; k <= i; k++) {
				if (M < e[k])M = e[k];
				if (m > e[k])m = e[k];
			}
			dp[i] = max(dp[i], dp[j-1] + M - m);
		}
	}

	printf("%d\n", dp[n]);

}