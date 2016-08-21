#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int d[203][203];

int main() {

	int n;
	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
			if (!d[i][j])d[i][j] = INT_MAX;
			else
				d[i][j] = 1;
		}
		d[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((d[i][k] | d[k][j]) == INT_MAX)continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	bool flag = true;

	int p = -1;

	for (int i = 1; i <= m; i++) {

		int c;
		scanf("%d", &c);

		if (p == -1) {
			p = c;
			continue;
		}

		if (d[p][c] == INT_MAX)flag = false;

		p = c;
	}

	if (flag)printf("YES\n");
	else
		printf("NO\n");

}