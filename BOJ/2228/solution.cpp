#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m;

int s[103];
int dp[103][103];

int dy(int c, int k) {

	if (k == m)return 0;
	else if (k != m && c > n)return (INT_MIN>>4);

	if (dp[c][k] != (INT_MIN>>1))return dp[c][k];

	dp[c][k] = (INT_MIN>>4);

	int exc = 0;
	if (c)exc = -s[c - 1];

	int le = c;
	if (c == 0)le = 1;

	for (int i = le; i <= n; i++) {
		dp[c][k] = max(dp[c][k], s[i] + exc + dy(i+2, k+1));
	}

	dp[c][k] = max(dp[c][k], dy(c + 1, k));

	return dp[c][k];

}

int main() {

	scanf("%d %d", &n, &m);

	dp[0][0] = INT_MIN >> 1;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
		for (int j = 0; j <= min(i, m); j++)dp[i][j] = INT_MIN >> 1;
	}

	printf("%d\n", dy(0, 0));

}