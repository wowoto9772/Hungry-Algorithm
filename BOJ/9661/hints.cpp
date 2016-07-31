#include <stdio.h>
#include <memory.h>

int dp[1005][2];

int n;

int dy(int c, int p) {

	if (c == n) {
		return !p;
	}

	if (dp[c][p] != -1)return dp[c][p];

	for (int i = 1; c + i <= n; i <<= 2) {
		dp[c][p] = dy(c + i, !p);
		if (dp[c][p] == p)return dp[c][p];
	}

	return dp[c][p];
}

int main()
{

	for (n = 1; n <= 50; n++) {

		dp[0][0] = -1;
		for (int i = 1; i <= n; i++)dp[i][0] = dp[i][1] = -1;

		if (dy(0, 0) == 0)printf("SK\n");
		else
			printf("CY\n");

	} // S C S S C

}