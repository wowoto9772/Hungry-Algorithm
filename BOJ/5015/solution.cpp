#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char ptn[103];
char str[103];

int dp[103][103];

int dy(int p, int s) {

	if (p == -1 || s == -1) {
		if (p == 0 && ptn[p] == '*')return 1;
		if (p == s)return 1;
		return 0;
	}
	if (dp[p][s] != -1)return dp[p][s];

	dp[p][s] = 0;

	if (ptn[p] == '*') {
		dp[p][s] = max(max(dy(p, s - 1), dy(p-1, s-1)), dy(p - 1, s));
	}
	else {
		if (ptn[p] == str[s]) {
			dp[p][s] = dy(p - 1, s - 1);
		}
	}

	return dp[p][s];

}

int main() {

	scanf("%s", ptn);

	int s = strlen(ptn);

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		int l = strlen(str);

		for (int j = 0; j < s; j++)for (int k = 0; k < l; k++)dp[j][k] = -1;

		if (dy(s - 1, l - 1)) {
			printf("%s\n", str);
		}

	}

}