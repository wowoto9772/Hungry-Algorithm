#include <stdio.h>
#include <limits.h>

#include <functional>

#include <vector>
#include <queue>

using namespace std;

#define c first
#define v second

vector < vector < pair <int, int> > > lnk;

int d[10003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	lnk.resize(m + 1);

	for (int i = 1; i <= n; i++) {

		int a, b, cc;
		scanf("%d %d %d", &a, &b, &cc);

		lnk[a].emplace_back(cc, b);

	}

	for (int i = 0; i <= m; i++) {
		d[i] = INT_MAX;
		if (i != m) {
			lnk[i].emplace_back(m - i, m);
			lnk[i].emplace_back(1, i + 1);
		}
	}

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > q;

	d[0] = 0;
	q.emplace(0, 0);

	while (!q.empty()) {

		pair <int, int> f = q.top(); q.pop();

		if (d[f.v] < f.c)continue;

		for (int i = 0; i < lnk[f.v].size(); i++) {

			pair <int, int> g = lnk[f.v][i];

			g.c += f.c;

			if (d[g.v] > g.c) {
				d[g.v] = g.c;
				q.emplace(g);
			}

		}

	}

	printf("%d\n", d[m]);

}