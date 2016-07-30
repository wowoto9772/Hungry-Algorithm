#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

bool chk[1003];
int stk[1003], grp[1003];
int top, gn;

vector < vector <int> > pnt[2];
vector < vector <int> > grpd;

void dfs(int c, int e) {

	if (!e) {
		if (chk[c])return;
		chk[c] = true;
	}
	else {
		if (grp[c])return;
		grp[c] = gn;
	}

	for (int i = 0; i < pnt[e][c].size(); i++) {
		dfs(pnt[e][c][i], e);
	}

	if (!e) {
		stk[top++] = c;
	}
}

int main() {

	int n, cap;
	scanf("%d %d", &n, &cap);

	for (int i = 0; i <= 1; i++)pnt[i].resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);

		pnt[0][a].push_back(i);

		pnt[1][i].push_back(a);

	}

	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (!grp[stk[i]])++gn;
		dfs(stk[i], 1);
	}

	grpd.resize(gn + 1);

	for (int i = 1; i <= n; i++) {
		grpd[grp[i]].push_back(i);
	}

	vector <int> src;

	for (int i = 1; i <= gn; i++) {

		bool pos = true;
		for (int j = 0; pos && j < grpd[i].size(); j++) {
			int k = grpd[i][j];
			for (int l = 0; pos && l < pnt[1][k].size(); l++) {
				if (grp[pnt[1][k][l]] != i) {
					pos = false;
				}
			}
		}

		if (pos)src.push_back(i);
	}

	bool dp[1003] = { 0 };
	dp[0] = true;

	bool used[1003] = { 0 };

	for (int i = 0; i < src.size(); i++) {

		queue <int> g;
		g.push(src[i]);

		used[src[i]] = true;

		int le = grpd[src[i]].size();
		int ri = le;

		vector <int> p;

		while (!g.empty()) {
			
			int a = g.front(); g.pop();

			for (int j = 0; j < grpd[a].size(); j++) {
				for (int k = 0; k < pnt[0][grpd[a][j]].size(); k++) {
					int b = grp[pnt[0][grpd[a][j]][k]];
					if (used[b])continue;
					used[b] = true;
					ri++;
					g.push(b);
				}
			}

		}

		for (int j = cap - 1; j >= 0; j--) {
			if (dp[j]) {
				for (int k = le; k <= ri && j+k <= cap; k++) {
					dp[j+k] = true;
				}
			}
		}

	}

	for (int i = cap; i >= 0; i--) {
		if (dp[i]) {
			printf("%d\n", i);
			break;
		}
	}

}
