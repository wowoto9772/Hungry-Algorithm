#include <stdio.h>
#include <algorithm>

using namespace std;

int x[30003];
int dp[30003][13];

int A(int n) {

	int s[11];
	int ret = 0;

	for (int i = 1; i <= 10; i++)s[i] = -1;

	for (int i = 0; i < n; i++) {

		int t = x[i];
		dp[i][t] = max(dp[i][t], 1);

		for (int j = 1; j <= t; j++) {
			if (s[j] == -1)continue;
			dp[i][t] = max(dp[i][t], dp[s[j]][j] + 1);
		}

		s[t] = i;
		ret = max(ret, dp[i][t]);
	}

	return ret;
}

int main()
{

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	int ans = A(n);

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 10; j++)dp[i][j] = 0;
	}

	reverse(x, x + n);

	ans = max(ans, A(n));

	printf("%d\n", n - ans);
}