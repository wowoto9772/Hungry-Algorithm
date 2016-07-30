#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

class ele {
public:

	int v, c;

	ele() {}
	ele(int a, int b) { v = a, c = b; }

};

int d[2][1003];

int main() {

	int n, m, c;
	scanf("%d %d %d", &n, &m, &c);

	vector < vector <ele> > lnk[2];

	for (int i = 0; i <= 1; i++)lnk[i].resize(n + 1);

	for (int i = 1; i <= m; i++) {

		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);

		lnk[0][a].emplace_back(b, x);
		lnk[1][b].emplace_back(a, x);

	}

	for (int i = 1; i <= n; i++)d[0][i] = d[1][i] = INT_MAX;

	queue <ele> q[2];

	for (int i = 0; i <= 1; i++) {

		q[i].emplace(c, 0);
		d[i][c] = 0;

		while (!q[i].empty()) {

			ele f = q[i].front(); q[i].pop();

			for (int j = 0; j < lnk[i][f.v].size(); j++) {

				ele g = lnk[i][f.v][j];
				
				int nc = f.c + g.c;

				if (d[i][g.v] > nc) {

					d[i][g.v] = nc;

					g.c = nc;

					q[i].emplace(g);

				}

			}

		}

	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int g = d[0][i] + d[1][i];

		ans = max(ans, g);

	}

	printf("%d\n", ans);

}