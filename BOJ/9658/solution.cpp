#include <stdio.h>
#include <memory.h>

int dp[1005][2];

int n;

int dy(int c, int p) {

	if (c == n) {
		return p;
	}
	else if (c > n)return -1;

	if (dp[c][p] != -1)return dp[c][p];

	dp[c][p] = dy(c + 4, !p);
	if (dp[c][p] == p)return dp[c][p];
	dp[c][p] = dy(c + 3, !p);
	if (dp[c][p] == p)return dp[c][p];
	dp[c][p] = dy(c + 1, !p);
	if (dp[c][p] == p)return dp[c][p];

	return dp[c][p];
}

int main()
{

	scanf("%d", &n);

	dp[0][0] = -1;
	for (int i = 1; i <= n; i++)dp[i][0] = dp[i][1] = -1;
	
	if (dy(0, 0) == 0)printf("SK\n");
	else
		printf("CY\n");

}