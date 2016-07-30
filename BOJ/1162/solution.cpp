#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele {
public:
	int v, c, k;
	ele() {}
	ele(int v_, int c_, int k_) { v = v_, c = c_, k = k_; }
	bool operator<(const ele &A)const {
		if (c == A.c)return k < A.k;
		return c > A.c;
	}
};

class dat {
public:
	int v, c;
	dat() {}
	dat(int a, int b) { v = a, c = b; }
};

bool chk[10003][23];
int d[10003][23];

int main(){

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)for (int j = 0; j <= k; j++)d[i][j] = INT_MAX;

	vector < vector < dat > > lnk;
	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		lnk[a].emplace_back(b, c);
		lnk[b].emplace_back(a, c);
	}

	priority_queue <ele> q;
	q.emplace(1, 0, k);

	while (!q.empty()) {
		
		ele f = q.top(); q.pop();
		
		if (chk[f.v][f.k])continue;
		chk[f.v][f.k] = true;
		
		for (int j = 0; j < lnk[f.v].size(); j++) {

			dat a = lnk[f.v][j];
			if (!chk[a.v][f.k] && d[a.v][f.k] > f.c + a.c) {

				d[a.v][f.k] = f.c + a.c;
				
				ele g = f;
				g.v = a.v;
				g.c += a.c;

				q.emplace(g);

			}
			if (f.k) {

				ele g = f;
				g.k--;

				if (!chk[a.v][g.k] && d[a.v][g.k] > g.c) {

					d[a.v][g.k] = g.c;

					g.v = a.v;

					q.emplace(g);

				}
			}

		}

	}

	int ans = INT_MAX;
	for (int i = 0; i <= k; i++)ans = min(ans, d[n][i]);

	printf("%d\n", ans);

}