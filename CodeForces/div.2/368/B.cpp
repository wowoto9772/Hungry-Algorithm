#include <stdio.h>
#include <limits.h>

#include <functional>
#include <queue>
#include <vector>

#define ll long long

using namespace std;

#define c first
#define v second

#define LMAX 1LL<<60

vector < vector < pair<ll, int> > > lnk;

bool nt[100003];
ll d[100003];

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(c, b);
		lnk[b].emplace_back(c, a);

	}

	priority_queue < pair <ll, int >, vector < pair <ll, int> >, greater< pair <ll, int> > > q;

	for (int i = 1; i <= n; i++)d[i] = LMAX;

	for (int i = 1; i <= k; i++) {

		int x;
		scanf("%d", &x);

		nt[x] = true;

		d[x] = 0;

		q.emplace(0, x);

	}

	while (!q.empty()) {

		pair <ll, int> f = q.top(); q.pop();

		if (d[f.v] < f.c)continue;

		for (int i = 0; i < lnk[f.v].size(); i++) {

			pair <ll, int> g = lnk[f.v][i];

			g.c += f.c;

			if (d[g.v] > g.c) {
				d[g.v] = g.c;
				q.emplace(g);
			}

		}

	}

	ll ans = LMAX;

	for (int i = 1; i <= n; i++) {
		if (nt[i])continue;
		ans = min(ans, d[i]);
	}

	if (ans == LMAX)ans = -1;

	printf("%lld\n", ans);

}