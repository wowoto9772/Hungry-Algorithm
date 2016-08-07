#include <stdio.h>
#include <algorithm>

using namespace std;

int d[53][53];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = 54321;
			char x;
			scanf(" %c", &x);
			if (x == 'Y')d[i][j] = 1;
		}
		d[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int cc = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			cc += d[i][j] <= 2;
		}
		ans = max(ans, cc);
	}

	printf("%d\n", ans);

}