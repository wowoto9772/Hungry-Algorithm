#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele {
public:
	int v, t, m;
	ele() {}
	ele(int a, int b, int c) { v = a, t = b, m = c; }

	bool operator<(const ele &A)const {
		return m > A.m;
	}

};

bool chk[103][10003];
int d[103][10003]; // p, t

int main() {

	int n, t, m;
	scanf("%d %d %d", &n, &t, &m);

	for (int i = 1; i <= n; i++)for (int j = 0; j <= t; j++)d[i][j] = INT_MAX;

	vector < vector <ele> > lnk;
	lnk.resize(n + 1);

	int c;
	scanf("%d", &c);

	for (int i = 1; i <= c; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		int x, y;
		scanf("%d %d", &x, &y);

		lnk[a].emplace_back(b, x, y);
		lnk[b].emplace_back(a, x, y);

	}

	priority_queue <ele> q;
	d[1][0] = 0;

	q.emplace(1, 0, 0);
	
	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (chk[f.v][f.t])continue;
		chk[f.v][f.t] = true;

		for (int i = 0; i < lnk[f.v].size(); i++) {
			
			ele g = lnk[f.v][i];
			g.t += f.t;
			g.m += f.m;

			if (g.t <= t) {

				if (g.m <= m) {


					if (d[g.v][g.t] > g.m) {
						d[g.v][g.t] = g.m;
						q.emplace(g);
					}

				}

			}

		}

	}

	int ans = INT_MAX;
	for (int i = 0; i <= t; i++)ans = min(ans, d[n][i]);

	if (ans == INT_MAX)ans = -1;
	
	printf("%d\n", ans);

}