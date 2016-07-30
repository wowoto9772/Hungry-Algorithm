#include <stdio.h>
#include <algorithm>

using namespace std;

int a[10003][2];

int dp[10003][4][4];

int n, m;

int starts;
int ends;

int xb, xt;
int yb, yt;

int dy(int c, int t, int b) {

	if (c > ends)return 0;

	if (dp[c][t][b] != -1)return dp[c][t][b];

	int &ret = dp[c][t][b];

	ret = 2 * n;

	if (c == starts) {
		t |= yt;
		b |= yb;
	}

	if (c == ends) {

		t |= xt;
		b |= xb;

		if (t && b)ret = 0;
		else if (t || b)ret = 1;
		else {
			if (a[c][0] + a[c][1] <= m)ret = 1;
			else
				ret = 2;
		}

	}
	else {
		if (t && b)ret = dy(c + 1, t >> 1, b >> 1);
		else if (!t && !b && a[c][0] + a[c][1] <= m) {
			ret = min(ret, 1 + dy(c, 1, 1));
		}

		if (!t) {
			if (a[c][0] + a[c + 1][0] <= m)ret = min(ret, 1 + dy(c, 3, b));
			ret = min(ret, 1 + dy(c, 1, b));
		}
		else if (!b) {
			if (a[c][1] + a[c + 1][1] <= m)ret = min(ret, 1 + dy(c, t, 3));
			ret = min(ret, 1 + dy(c, t, 1));
		}
	}

	return ret;

}

void Init() { for (int i = 0; i < n; i++)for (int j = 0; j < 4; j++)for (int k = 0; k < 4; k++)dp[i][j][k] = -1; }

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)scanf("%d", &a[i][0]);
		for (int i = 0; i < n; i++)scanf("%d", &a[i][1]);

		int ans = 2 * n;

		if (n == 1) {
			if (a[0][0] + a[0][1] <= m)ans = 1;
			else
				ans = 2;
		}
		else {

			// #1

			// n-1 ~ 0 (top)
			// n-1 ~ 0 (bot)

			int ret = 0;

			if (a[0][0] + a[n - 1][0] <= m)ret++;
			else
				ret += 2;

			if (a[0][1] + a[n - 1][1] <= m)ret++;
			else
				ret += 2;

			xt = xb = yt = yb = 0;

			Init();
			ends = n - 2;
			ans = min(ans, ret + dy(1, 0, 0));

			// #2 : basic
			// 0 ~ n-1
			Init();
			ends = n - 1;
			ans = min(ans, dy(0, 0, 0));

			// #3
			// n-1 ~ 0 (top)

			ret = 0;

			if (a[n - 1][0] + a[0][0] <= m)ret++;
			else
				ret += 2;

			Init();
			xt = yt = 1;
			xb = yb = 0;
			ans = min(ans, ret + dy(0, 0, 0));

			// #4
			// n-1 ~ 1 (bot)

			Init();
			yt = xt = 0;
			yb = xb = 1;
			ret = 0;

			if (a[n - 1][1] + a[0][1] <= m)ret++;
			else
				ret += 2;

			ans = min(ans, ret + dy(0, 0, 0));

		}

		printf("%d\n", ans);
	}

}