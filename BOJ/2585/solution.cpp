#include <stdio.h>
#include <math.h>

#include <queue>
#include <algorithm>

using namespace std;

int c[1003][1003];

int x[1003], y[1003];

int chk[1003];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	x[0] = y[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	x[n + 1] = y[n + 1] = 10000;

	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			int cc = (x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]);
			double m = sqrt((double)cc);

			c[i][j] = c[j][i] = (int) ceil(m / 10.0);
		}
	}

	int l = 1, r = 1503, m;

	int ans = 1505;

	while (l <= r) {

		m = (l + r) / 2;

		for (int i = 1; i <= n + 1; i++)chk[i] = -1;

		queue <int> q;
		q.push(0);

		while (!q.empty() && chk[n+1] == -1) {

			int f = q.front(); q.pop();

			for (int j = 1; j <= n+1; j++) {

				if (chk[j] == -1) {

					if (c[f][j] <= m) {

						chk[j] = chk[f] + 1;

						q.push(j);

					}

				}

			}


		}

		if (chk[n+1] != -1 && chk[n + 1] <= k+1) { // for end
			ans = min(ans, m);
			r = m - 1;
		}
		else {
			l = m + 1;
		}

	}

	printf("%d\n", ans);

}a