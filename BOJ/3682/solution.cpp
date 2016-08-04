#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > lnk[2][20003];

int grp[20003], stk[20003];
bool vst[20003];

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

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {

			lnk[0][i].clear(), lnk[1][i].clear();
			grp[i] = 0;
			vst[i] = false;

		}

		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			lnk[0][a].push_back(b);
			lnk[1][b].push_back(a);

		}

		gtop = top = 0;

		for (int i = 1; i <= n; i++)dfs(0, i);

		for (int i = n - 1; i >= 0; i--) {
			if (grp[stk[i]])continue;
			gtop++;
			dfs(1, stk[i]);
		}

		// make sexy graph !

		vector < vector <int> > graph;
		vector <int> in, out;

		graph.resize(gtop + 1);

		in.resize(gtop + 1);
		out.resize(gtop + 1);

		for (int i = 1; i <= n; i++) {

			for (int j = 0; j < lnk[0][i].size(); j++) {

				int k = lnk[0][i][j];

				if (grp[i] != grp[k])graph[grp[i]].push_back(grp[k]);

			}

		}

		for (int i = 1; i <= gtop; i++) {

			sort(graph[i].begin(), graph[i].end());
			graph[i].resize(unique(graph[i].begin(), graph[i].end()) - graph[i].begin());

			for (int j = 0; j < graph[i].size(); j++) {
				in[i]++;
				out[graph[i][j]]++;
			}

		}
		
		if (gtop == 1)printf("0\n");
		else {

			int _in = 0, _out = 0;

			for (int i = 1; i <= gtop; i++) {
				if (!in[i])_in++;
				if (!out[i])_out++;
			}

			printf("%d\n", max(_in, _out));
		}

	}

}