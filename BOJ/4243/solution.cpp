#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <algorithm>

#define ll long long

using namespace std;

ll s[103];
int n;

ll dp[103][103][2];

ll dy(int le, int ri, int r) {

	ll &ret = dp[le][ri][r];

	if (ret != -1)return ret;

	ret = LLONG_MAX;

	ll rem = (n - ri) + (le - 1);

	if (r) {
		if (le > 1)ret = min(ret, dy(le - 1, ri, 0) + rem * (s[ri] - s[le - 1]));
		if (ri < n)ret = min(ret, dy(le, ri + 1, 1) + rem * (s[ri + 1] - s[ri]));
	}
	else {
		if (le > 1)ret = min(ret, dy(le - 1, ri, 0) + rem * (s[le] - s[le - 1]));
		if (ri < n)ret = min(ret, dy(le, ri + 1, 1) + rem * (s[ri + 1] - s[le]));
	}

	return ret;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		int a;
		scanf("%d", &a);

		for (int i = 2; i <= n; i++) {
			scanf("%lld", &s[i]);
			s[i] += s[i - 1];
		}

		for (int i = 1; i <= n; i++)for (int j = i; j <= n; j++)dp[i][j][0] = dp[i][j][1] = -1;

		dp[1][n][0] = dp[1][n][1] = 0;

		printf("%lld\n", dy(a, a, 1));
	}

}