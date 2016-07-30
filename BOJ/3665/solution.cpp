#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int o[503]; // orginal
int in[503];

bool win[503][503];
bool ign[503][503];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &o[i]);
			in[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				win[i][j] = false;
				ign[i][j] = false;
			}
		}

		vector < vector <int> > nxt;
		nxt.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				in[o[j]]++;
				nxt[o[i]].push_back(o[j]);
				win[o[i]][o[j]] = true;
			}
		}

		int m;
		scanf("%d", &m);

		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (win[a][b]) {
				in[b]--;
				in[a]++;
				ign[a][b] = true;
				nxt[b].push_back(a);
			}
			else {
				in[b]++;
				in[a]--;
				ign[b][a] = true;
				nxt[a].push_back(b);
			}
		}

		bool flag = false;

		queue <int> q;

		bool many = false;

		int flg = 0;

		for (int i = 1; i <= n; i++) {
			if (!in[i]) {
				q.push(i);
				flg++;
			}
		}

		if (flg >= 2)many = true;

		vector <int> ans;

		while (!q.empty() && !flag) {
			int f = q.front(); q.pop();

			ans.push_back(f);

			flg = 0;

			for (int i = 0; i < nxt[f].size(); i++) {
				int c = nxt[f][i];
				if (ign[f][c])continue;
				in[c]--;
				if (!in[c]) {
					flg++;
					q.push(c);
				}
			}

			if (flg >= 2)many = true;

		}

		if (ans.size() != n)printf("IMPOSSIBLE");
		else {
			if (many) {
				printf("?");
			}
			else {
				int top = 0;
				for (int i = 0; i < n; i++) {
					printf("%d ", ans[i]);
				}
			}
		}

		printf("\n");
	}
}

/*
	4
	1 2 3 4
	1
	1 2
*/