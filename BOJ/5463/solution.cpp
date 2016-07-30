#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define ll long long

using namespace std;

ll dp[53][53][53][53];
ll sum[53][53];

ll dy(int r, int c, int r2, int c2) {

	if (dp[r][c][r2][c2] != -1)return dp[r][c][r2][c2];

	ll &ret = dp[r][c][r2][c2];

	ret = INT_MAX;

	ll cst = sum[r2][c2] - sum[r2][c - 1] - sum[r - 1][c2] + sum[r - 1][c - 1];

	if (r == r2 && c == c2)ret = 0;
	else {

		for (int i = r; i < r2; i++) {
			ret = min(ret, dy(r, c, i, c2) + dy(i + 1, c, r2, c2) + cst);
		}

		for (int i = c; i < c2; i++) {
			ret = min(ret, dy(r, c, r2, i) + dy(r, i + 1, r2, c2) + cst);
		}

	}

	return ret;

}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int v;
			scanf("%d", &v);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + v;
			for (int a = i; a <= n; a++) {
				for (int b = j; b <= m; b++) {
					dp[i][j][a][b] = -1;
				}
			}
		}
	}

	printf("%lld\n", dy(1, 1, n, m));
}