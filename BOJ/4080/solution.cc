#include <cstdio>
#include <algorithm>

using namespace std;

int e[1003];
int dp[1003][1003];

int dy(int i, int j) {
	int &ret = dp[i][j];
	if (ret != -987654321)return dp[i][j];

	if (i + 1 == j) {
		ret = abs(e[i] - e[j]);
	}
	else {

		if (e[i + 1] > e[j])ret = max(ret, e[i] - e[i + 1] + dy(i + 2, j));
		else if (e[i + 1] < e[j])ret = max(ret, e[i] - e[j] + dy(i + 1, j - 1));
		else
			ret = max(ret, e[i] - e[i + 1] + dy(i + 2, j));

		if (e[i] > e[j - 1])ret = max(ret, e[j] - e[i] + dy(i + 1, j - 1));
		else if (e[i] < e[j - 1])ret = max(ret, e[j] - e[j - 1] + dy(i, j - 2));
		else {
			ret = max(ret, e[j] - e[i] + dy(i + 1, j - 1));
		}

	}
	return ret;
}

int main()
{
	int tc = 0;
	int n;

	while (scanf("%d", &n) == 1 && n) {

		for (int i = 0; i < n; i++)scanf("%d", &e[i]);
		for (int i = 0; i < n; i++)for (int j = i; j < n; j++)dp[i][j] = -987654321;

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ++tc, dy(0, n - 1));
	}
}