#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll dp[37][37];
char str[37][37];
int n;

ll dy(int i, int j) {

	if (i == n - 1 && j == n - 1)return 1;
	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = 0;

	int d = str[i][j] - '0';

	if (i + d < n)dp[i][j] += dy(i + d, j);
	if (j + d < n)dp[i][j] += dy(i, j + d);

	return dp[i][j];

}

int main() {

	while (scanf("%d", &n) == 1 && n >= 0) {

		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			for (int j = 0; j < n; j++)dp[i][j] = -1;
		}

		printf("%lld\n", dy(0, 0));

	}

}