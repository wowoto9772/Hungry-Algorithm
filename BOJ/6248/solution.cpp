#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

class ele {
public:
	int a, c;
	ele() {}
	ele(int a_, int c_) {
		a = a_, c = c_;
	}

	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

int d[1003];

int main() {

	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	vector < vector <ele> > lnk;
	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(b, c);
		lnk[b].emplace_back(a, c);

	}

	for (int i = 1; i <= n; i++)d[i] = INT_MAX;

	priority_queue <ele> q;
	q.emplace(x, 0);

	d[x] = 0;

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (d[f.a] < f.c)continue;

		for (int i = 0; i < lnk[f.a].size(); i++) {

			ele g = lnk[f.a][i];

			g.c += f.c;

			if (d[g.a] > g.c) {
				d[g.a] = g.c;
				q.emplace(g);
			}

		}

	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
	}

	printf("%d\n", ans << 1);

}