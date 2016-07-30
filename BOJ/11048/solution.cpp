#include <stdio.h>
#include <algorithm>

using namespace std;

int a[1003][1003];
int dp[1003][1003];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + a[i][j];
		}
	}

	printf("%d\n", dp[r][c]);

}