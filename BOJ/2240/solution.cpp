#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1003][33][2];
int t[1003];
int n;

int dy(int c, int w, int p) {

	if (w < 0)return -1;
	if (c == n + 1)return 0;

	int &ret = dp[c][w][p];

	if (ret != -1)return ret;

	ret = (t[c] == p);

	ret += max(dy(c + 1, w - 1, !p), dy(c + 1, w, p));

	return ret;

}

int main() {

	int w;
	scanf("%d %d", &n, &w);

	t[0] = -1;

	for (int i = 1; i <= n; i++)for (int j = 0; j <= w; j++)for (int k = 0; k < 2; k++)dp[i][j][k] = -1;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		t[i]--;
	}

	dp[0][w][0] = -1;
	printf("%d\n", dy(0, w, 0));

}
