#include <stdio.h>
#include <algorithm>

#define mval (-100*1000*1002)

using namespace std;

int e[1003][1003];
int dp[1003][1003][2];

int n, m;

int dy(int i, int j, int d) {

	if (i > n)return mval;
	if (i == n && j == m)return e[i][j];
	if (i == n && d == 0)return mval;

	if (dp[i][j][d] != -1)return dp[i][j][d];

	dp[i][j][d] = mval;

	if (d) {
		// right
		if(j < m)dp[i][j][d] = e[i][j] + dy(i, j + 1, d);
	}
	else {
		// left
		if (j > 1)dp[i][j][d] = e[i][j] + dy(i, j - 1, d);
	}

	dp[i][j][d] = max(dp[i][j][d], e[i][j] + max(dy(i+1, j, 0), dy(i+1, j, 1)));

	return dp[i][j][d];

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &e[i][j]);
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	printf("%d\n", max(dy(1, 1, 0), dy(1, 1, 1)));

}