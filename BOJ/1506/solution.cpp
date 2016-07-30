#include <stdio.h>
#include <limits.h>

#include <algorithm>

using namespace std;

int d[103][103];
int p[103];

bool tst[103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		for (int j = 1; j <= n; j++)d[i][j] = INT_MAX;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char x;
			scanf(" %c", &x);
			if (x == '1')d[i][j] = 1;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX)continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		if (tst[i])continue;

		tst[i] = true;

		int pay = p[i];

		for (int j = i + 1; j <= n; j++) {

			if (tst[j])continue;

			if (d[i][j] == INT_MAX || d[j][i] == INT_MAX) continue;

			tst[j] = true;

			pay = min(pay, p[j]);

		}

		ans += pay;

	}

	printf("%d\n", ans);

}