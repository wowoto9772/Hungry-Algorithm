#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

class ele {
public:
	ele() {}
	ele(int a, int b) { v = a, c = b; }
	int v, c;
	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

int p[103];
int d[2][1003];

int main() {

	int n, v, e;
	scanf("%d %d %d", &n, &v, &e);

	int a[2];
	for (int i = 0; i < 2; i++)scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)scanf("%d", &p[i]);

	for (int i = 0; i < 2; i++)for (int j = 1; j <= v; j++)d[i][j] = INT_MAX;

	vector < vector < ele > > lnk;
	lnk.resize(v + 1);

	for (int i = 1; i <= e; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		lnk[x].emplace_back(y, z);
		lnk[y].emplace_back(x, z);
	}

	bool chk[1003];

	for (int i = 0; i < 2; i++) {

		for (int j = 1; j <= v; j++)chk[j] = false;

		priority_queue <ele> q;
		q.emplace(a[i], 0);
		d[i][a[i]] = 0;

		while (!q.empty()) {

			ele f = q.top(); q.pop();

			if (chk[f.v])continue;
			chk[f.v] = true;

			for (int j = 0; j < lnk[f.v].size(); j++) {

				ele g = lnk[f.v][j];

				g.c += f.c;

				if (d[i][g.v] > g.c) {
					d[i][g.v] = g.c;
					q.emplace(g);
				}

			}

		}

		for (int j = 1; j <= v; j++)if (d[i][j] == INT_MAX)d[i][j] = -1;

	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += d[0][p[i]] + d[1][p[i]];
	}

	printf("%d\n", ans);



}