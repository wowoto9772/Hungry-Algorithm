#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

ll dp[203][203];
int N, m, M, T, R;

ll dy(int n, int p) {

	if (n == N)return 0;
	if (dp[n][p] != -1)return dp[n][p];

	ll &ret = dp[n][p];

	ret = INT_MAX;

	if (p + T <= M)ret = min(ret, 1 + dy(n + 1, p + T));
	ret = min(ret, 1 + dy(n, max(p - R, m)));

	return dp[n][p];

}

int main() {

	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

	for (int i = 0; i <= N; i++)for (int j = m; j <= M; j++)dp[i][j] = -1;

	int g = dy(0, m);

	if (g == INT_MAX)g = -1;
	printf("%d\n", g);

}