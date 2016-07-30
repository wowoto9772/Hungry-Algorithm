#include <stdio.h>

int dp[103][2][103];
int n, k;

int dy(int c, int f, int d) {

	if (c == n + 1) {
		return d == k;
	}

	int &ret = dp[c][f][d];

	if (ret != -1)return ret;

	ret = 0;

	if (f == 1) {
		if (d < k) {
			ret += dy(c + 1, 1, d + 1);
		}
	}
	else {
		ret += dy(c + 1, 1, d);
	}

	ret += dy(c + 1, 0, d);

	return ret;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++)for (int j = 0; j <= k; j++)dp[i][0][j] = dp[i][1][j] = -1;

		printf("%d\n", dy(1, 0, 0));

	}

}