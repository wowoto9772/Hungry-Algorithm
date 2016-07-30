#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[103][23][53];
bool ho[103][23];
int n;

int dy(int c, int h, int k) {

	if (c == n)return 0;

	int &ret = dp[c][h][k];
	if (ret != -1)return ret;

	ret = 53;

	for (int i = 1; i <= 20; i++) {
		if (ho[c + 1][i]) {
			if (i == min(2 * h, 20) || abs(h-i) <= 1)ret = min(ret, dy(c + 1, i, k));
			else {
				if (k) {
					ret = min(ret, 1 + dy(c + 1, i, k - 1));
				}
			}
		}
	}

	return ret;

}

int main() {

	int k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
	
		int c;
		scanf("%d", &c);

		for (int j = 1; j <= c; j++) {
			int x;
			scanf("%d", &x);
			ho[i][x] = true;
		}
	}

	memset(dp, 0xff, sizeof(dp));

	int x = dy(0, 1, k);

	if (x > k)x = -1;

	printf("%d\n", x);

}