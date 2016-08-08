#include <stdio.h>
#include <limits.h>

#include <algorithm>

using namespace std;

int n;

int c[203];
int dp[203][203];

int dy(int l, int r) {

	if (l == r)return 0;

	int &ret = dp[l][r];
	if (ret != -1)return ret;

	ret = INT_MAX;

	for (int k = l; k < r; k++) {

		int add = !(c[l] == c[r]);
		ret = min(ret, dy(l, k) + dy(k + 1, r) + add);

	}

	return ret;

		
}

int main() {

	scanf("%d %*d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &c[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dy(1, n));

}