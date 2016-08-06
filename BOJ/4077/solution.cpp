#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;


#define NMAX 18

vector <int> a[NMAX];
bool c[NMAX];
int low[NMAX];
int dfn[NMAX];
int parent[NMAX];
int cnt;
bool cut[NMAX];

vector < pair<int, int> > bridge;

void dfs(int x) {

	c[x] = true;

	dfn[x] = ++cnt;

	low[x] = cnt;

	int children = 0;

	for (int i = 0; i < a[x].size(); i++) {

		int y = a[x][i];

		if (!c[y]) {

			children += 1;

			parent[y] = x;

			dfs(y);

			low[x] = min(low[x], low[y]);

			if (!parent[x] && children >= 2) {

				cut[x] = true;

			}

			if (parent[x] && low[y] >= dfn[x]) {

				cut[x] = true;

			}

			if (low[y] > dfn[x]) {
				bridge.emplace_back(x, y);
			}

		}
		else if (y != parent[x]) {

			low[x] = min(low[x], dfn[y]);

		}

	}

}

class ele {
public:
	int a, b, c;
	ele() {}
	ele(int _a, int _b, int _c) {
		a = _a, b = _b, c = _c;
	}
};

vector <ele> edge;

int n, m;

bool hasBridge(int removed) {

	// initialization
	for (int i = 1; i <= n; i++) {
		cut[i] = dfn[i] = low[i] = 0;
		c[i] = false;
		a[i].clear();
	}
	cnt = 0;
	bridge.clear();

	for (int i = 0; i < edge.size(); i++) {

		if (removed & (1 << i))continue;

		a[edge[i].a].push_back(edge[i].b);
		a[edge[i].b].push_back(edge[i].a);

	}

	dfs(1);

	return !bridge.empty();

}

int dp[1 << 20];

int dy(int r) {

	if (dp[r] != -1)return dp[r];

	dp[r] = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (r & (1 << i))continue;
		dp[r] += edge[i].c;
	}

	for (int i = 0; i < edge.size(); i++) {

		if (r & (1 << i))continue;

		if (hasBridge(r | (1 << i)))continue;

		dp[r] = min(dp[r], dy(r | 1<<i));

	}

	return dp[r];

}

int main() {

	int tc = 0;

	while (scanf("%d %d", &n, &m) == 2) {

		if (!(n | m))break;

		tc++;

		edge.clear();

		for (int i = 0; i < m; i++) {

			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			edge.emplace_back(a, b, c);

		}

		for (int i = 0; i < (1 << m); i++)dp[i] = -1;
		
		if (hasBridge(0)) {
			printf("There is no reliable net possible for test case %d.", tc);
		}
		else {
			printf("The minimal cost for test case %d is %d.", tc, dy(0));
		}

		printf("\n");

	}


	return 0;

}