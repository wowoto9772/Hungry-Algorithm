#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int d[103][103];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (i != j)d[i][j] = INT_MAX;

	while (m--) {

		int a, b;
		scanf("%d %d", &a, &b);

		d[a][b] = d[b][a] = 1;

	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((d[i][k] | d[k][j]) == INT_MAX)continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = INT_MAX, x;

	for (int i = 1; i <= n; i++) {
		int cmp = 0;
		for (int j = 1; j <= n; j++) {
			cmp += d[i][j];
		}
		if (ans > cmp) {
			ans = cmp;
			x = i;
		}
	}

	printf("%d\n", x);

}