#include <stdio.h>
#include <algorithm>

using namespace std;

int c[1003];
int dp[1003][1003];

int dy(int i, int j) {

	if (i > j)return 0;
	if (dp[i][j] != -1)return dp[i][j];

	dp[i][j] = max(c[i] - dy(i + 1, j), c[j] - dy(i, j - 1));

	return dp[i][j];

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &c[i]);
			for (int j = i; j < n; j++)dp[i][j] = -1;
		}

		dy(0, n - 1);

		int l = 0, r = n - 1;

		int ans = 0;

		while (l <= r) {

			for (int i = 1; i <= 2 && l <= r; i++) {
				if (c[l] - dy(l + 1, r) > c[r] - dy(l, r - 1)) {

					if(i&1)ans += c[l];
					l = l + 1;

				}
				else {

					if (i & 1)ans += c[r];
					r = r - 1;

				}
			}

		}

		printf("%d\n", ans);

	}

}