#include <stdio.h>
#include <limits.h>

#include <string.h>

#include <algorithm>

using namespace std;

int c[18][18], dp[1 << 16];

char str[18];

int n, q;

int dy(int x, int k) {

	if (k >= q)return 0;
	if (dp[x] != -1)return dp[x];

	dp[x] = INT_MAX >> 3;

	for (int i = 0; i < n; i++) {
		if (x&(1 << i)) {
			for (int j = 0; j < n; j++) {
				if (x & (1 << j))continue;
				dp[x] = min(dp[x], c[i][j] + dy(x | (1 << j), k + 1));
			}
		}
	}

	return dp[x];

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &c[i][j]);
		}
	}

	for (int i = 0; i < (1 << n); i++)dp[i] = -1;

	scanf("%s", str);

	int s = strlen(str);

	int c = 0, k = 0;

	for (int i = 0; i < s; i++) {
		if (str[i] == 'Y')c |= 1 << i, k++;
	}

	scanf("%d", &q);

	int flg = dy(c, k);

	if (flg >= INT_MAX >> 3)flg = -1;

	printf("%d\n", flg);

}