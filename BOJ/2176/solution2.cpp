#include <stdio.h>
#include <limits.h>

#include <functional>

#include <vector>
#include <queue>

using namespace std;

#define cst first
#define v second

int dp[1003];
int c[1003];

vector < vector < pair<int, int> > > lnk;

int dy(int x) {

	if (x == 2)return 1;

	int &ret = dp[x];
	if (ret != -1)return ret;

	ret = 0;

	for (int j = 0; j < lnk[x].size(); j++) {

		int n = lnk[x][j].v;

		if (c[x] > c[n]) {
			ret += dy(n);
		}

	}

	return ret;

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(c, b);
		lnk[b].emplace_back(c, a);
	}

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > q;

	for (int i = 1; i <= n; i++)c[i] = INT_MAX;

	q.emplace(0, 2);

	c[2] = 0;

	while (!q.empty()) {

		pair <int, int> f = q.top(); q.pop();

		if (f.cst > c[f.v])continue;

		for (int j = 0; j < lnk[f.v].size(); j++) {

			pair <int, int> g = lnk[f.v][j];

			g.cst += f.cst;

			if (c[g.v] > g.cst) {
				c[g.v] = g.cst;
				q.emplace(g);
			}

		}


	}

	for (int i = 1; i <= n; i++)dp[i] = -1;

	printf("%d\n", dy(1));

}