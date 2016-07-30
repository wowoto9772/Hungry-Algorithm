#include <stdio.h>
#include <limits.h>

#include <queue>
#include <vector>

#define ll long long

using namespace std;

class ele {
public:
	
	int v;
	ll c;

	ele() {}
	ele(int a, ll b) { v = a, c = b; }

	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

bool eff[100003];
bool chk[100003];
ll di[100003];

bool imp[100003];

int main() {

	int n, m, k, s;
	scanf("%d %d %d %d", &n, &m, &k, &s);

	int c[2];
	scanf("%d %d", &c[0], &c[1]);

	vector < vector < int > > lnk;
	lnk.resize(n + 1);

	queue <ele> q;

	for (int i = 1; i <= k; i++) {

		int a;
		scanf("%d", &a);

		q.emplace(a, 0);
		imp[a] = true;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for (int i = 2; i <= n; i++)di[i] = LLONG_MAX;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (f.c < s) {

			for (int i = 0; i < lnk[f.v].size(); i++) {

				int d = lnk[f.v][i];

				if (!imp[d] && !eff[d]) {
					eff[d] = true;
					q.emplace(d, f.c + 1);
				}

			}

		}

	}

	priority_queue <ele> pq;

	pq.emplace(1, 0);
	di[1] = 0;

	while (!pq.empty()) {

		ele f = pq.top(); pq.pop();

		if (chk[f.v])continue;

		chk[f.v] = true;

		for (int i = 0; i < lnk[f.v].size(); i++) {

			ele g = { lnk[f.v][i], f.c };

			if (imp[g.v])continue; // 좀비도시

			g.c += c[eff[f.v]]; // 숙박

			if (!chk[g.v]) {

				if (di[g.v] > g.c) {
					di[g.v] = g.c;
					pq.emplace(g);
				}

			}

		}

	}

	printf("%lld\n", di[n] - c[eff[1]]);


}