#include <stdio.h>
#include <string.h>

char se[203], xy[203], sexy[406];

int dp[203][203];
int s, x;

int dy(int l, int r) {

	if (l == s && r == x)return 1;

	int &ret = dp[l][r];

	if (ret != -1)return ret;

	ret = 0;

	if (l < s) {
		if (se[l] == sexy[l + r])ret = dy(l + 1, r);
	}

	if (!ret) {
		if (r < x) {
			if (xy[r] == sexy[l + r])ret = dy(l, r + 1);
		}
	}

	return ret;

}

int main() {

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		scanf("%s %s", se, xy);
		scanf("%s", sexy);

		s = strlen(se), x = strlen(xy);

		for (int i = 0; i <= s; i++)for (int j = 0; j <= x; j++)dp[i][j] = -1;

		printf("Data set %d: %s\n", ++tc, dy(0, 0) ? "yes" : "no");

	}

}