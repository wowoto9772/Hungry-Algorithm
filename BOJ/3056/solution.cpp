#include <stdio.h>
#include <algorithm>

using namespace std;

double dp[1 << 20];
double p[23][23];

int m, n;

double dy(int s, int c) {

	if (s == m)return 100.0;
	if (dp[s] >= 0.0)return dp[s];

	dp[s] = 0.0;

	for (int i = 0; i < n; i++) {
		if (s & (1 << i))continue;
		dp[s] = max(dp[s], p[c][i] * dy(s | (1 << i), c + 1));
	}

	return dp[s];

}

int main() {

	scanf("%d", &n);

	m = (1 << n) - 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lf", &p[i][j]);
			p[i][j] /= 100.0;
		}
	}

	for (int i = 0; i < m; i++) {
		dp[i] = -1.0;
	}

	printf("%.7lf\n", dy(0, 0));

}