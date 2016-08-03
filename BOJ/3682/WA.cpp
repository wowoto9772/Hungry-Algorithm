#include <stdio.h>
#include <vector>

using namespace std;

vector < int > lnk[2][20003];

int in[20003], out[20003];
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

	if(!t)stk[top++] = c;

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			in[i] = out[i] = grp[i] = 0;
			lnk[0][i].clear(), lnk[1][i].clear();
			vst[i] = false;
		}

		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			out[a]++, in[b]++;

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

		int ans = gtop;
		
		bool flag = true;

		for (int i = 1; i <= n; i++)if (!(in[i] | out[i]))flag = false;

		ans -= flag;

		printf("%d\n", ans);

	}

}