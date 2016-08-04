#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>

using namespace std;

vector < int > lnk[2][500003];

int grp[500003], stk[500003], g[500003];

bool vst[500003];

int top, gtop;

void dfs(int t, int c) {

	if (!t) {
		if (vst[c])return;
		vst[c] = true;
	}
	else {
		if (grp[c])return;
		grp[c] = gtop;
	}

	for (int i = 0; i < lnk[t][c].size(); i++) {
		dfs(t, lnk[t][c][i]);
	}

	if (!t)stk[top++] = c;

}

vector < vector <int> > graph;
vector < int > gold, dp;
vector < bool > ends;

int dy(int c) {

	if (dp[c] != -1)return dp[c];

	dp[c] = 0;

	for (int j = 0; j < graph[c].size(); j++) {
		
		int d = graph[c][j];

		dp[c] = max(dp[c], gold[d] + dy(d));

	}

	if (dp[c] == 0 && !ends[c])dp[c] = INT_MIN;

	return dp[c];

}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		lnk[0][a].push_back(b);
		lnk[1][b].push_back(a);

	}

	for (int i = 1; i <= n; i++) {

		scanf("%d", &g[i]);

		grp[i] = 0;
		vst[i] = false;

	}


	gtop = top = 0;

	for (int i = 1; i <= n; i++)dfs(0, i);

	for (int i = n - 1; i >= 0; i--) {
		if (grp[stk[i]])continue;
		gtop++;
		dfs(1, stk[i]);
	}

	// make sexy graph !


	graph.resize(gtop + 1);
	gold.resize(gtop + 1);

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < lnk[0][i].size(); j++) {

			int k = lnk[0][i][j];

			if (grp[i] != grp[k])graph[grp[i]].push_back(grp[k]);

		}

		gold[grp[i]] += g[i];

	}

	// graph renewal
	for (int i = 1; i <= gtop; i++) {

		sort(graph[i].begin(), graph[i].end());
		graph[i].resize(unique(graph[i].begin(), graph[i].end()) - graph[i].begin());

	}


	dp.resize(gtop + 1);
	ends.resize(gtop + 1);

	for (int i = 1; i <= gtop; i++)dp[i] = -1;

	int s, r;
	scanf("%d %d", &s, &r);

	for (int i = 1; i <= r; i++) {
	
		int a;
		scanf("%d", &a);

		ends[grp[a]] = true;

	}

	printf("%d\n", gold[grp[s]] + dy(grp[s]));

}