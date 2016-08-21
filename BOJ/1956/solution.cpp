#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

int d[404][404];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = INT_MAX;
		}
	}

	while (m--) {

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (d[a][b] > c)d[a][b] = c;

	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((d[i][k] | d[k][j]) == INT_MAX)continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		ans = min(ans, d[i][i]);
	}

	if (ans == INT_MAX)ans = -1;

	printf("%d\n", ans);

}