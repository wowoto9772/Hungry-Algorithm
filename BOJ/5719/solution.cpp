#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#include <memory.h>

using namespace std;

class ele {
public:
	int a, c;
	bool operator<(const ele &a)const {
		return c > a.c;
	}
};

int main()
{
	int n, m, s, a;
	int x, y, z;

	while (scanf("%d %d", &n, &m) == 2 && n && m) {
		scanf("%d %d", &s, &a);

		vector < vector <ele> > lnk;
		lnk.resize(n + 1);

		ele p, f;

		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &x, &y, &z);
			p.a = y, p.c = z;
			lnk[x].push_back(p);
		}

		bool chk[502] = { 0 }, cant[502] = { 0 };
		int dij[502], agu[502], minv = INT_MAX;
		memset(dij, 0x4f, sizeof(dij));

		priority_queue <ele> Q;
		dij[s] = 0;
		p.a = s, p.c = 0;
		Q.push(p);

		while (!Q.empty()) { // find shortest path
			f = Q.top();
			Q.pop();

			if (chk[f.a])continue;

			chk[f.a] = true;

			for (int i = 0; i<lnk[f.a].size(); i++) {
				p = lnk[f.a][i];
				if (!chk[p.a] && dij[p.a] > dij[f.a] + p.c) {
					dij[p.a] = dij[f.a] + p.c;
					p.c = dij[p.a];
					if (p.a != a)Q.push(p);
				}
			}
		}

		minv = dij[a];

		memset(dij, 0x4f, sizeof(dij));
		memset(agu, 0xff, sizeof(agu));
		memset(chk, 0, sizeof(chk));

		dij[s] = 0;
		p.a = s, p.c = 0;
		Q.push(p);

		while (!Q.empty()) { // never visited
			f = Q.top();
			Q.pop();

			if (chk[f.a])continue;

			chk[f.a] = true;

			for (int i = 0; i<lnk[f.a].size(); i++) {
				p = lnk[f.a][i];
				if (!chk[p.a] && dij[p.a] >= dij[f.a] + p.c) {
					dij[p.a] = dij[f.a] + p.c;
					agu[p.a] = f.a;
					p.c = dij[p.a];

					if (p.a == a) {
						if (p.c == minv) {
							int back = agu[a];
							while (back != s) {
								cant[back] = true;
								back = agu[back];
							}
						}
					}
					else {
						Q.push(p);
					}
				}
			}
		}

		memset(dij, 0x4f, sizeof(dij));
		memset(chk, 0, sizeof(chk));

		f.a = s, f.c = 0;
		dij[s] = 0;
		Q.push(f);

		int ans = -1;

		while (!Q.empty()) { // find almost shortest path
			f = Q.top();
			Q.pop();

			if (chk[f.a])continue;

			chk[f.a] = true;

			if (f.a == a) {
				ans = f.c;
				break;
			}
			else {
				for (int i = 0; i<lnk[f.a].size(); i++) {
					p = lnk[f.a][i];
					if (!cant[p.a] && !chk[p.a] && dij[p.a] > dij[f.a] + p.c) {
						if (f.a == s && p.a == a && minv == f.c + p.c)continue;
						// it is possible that shortest path is starting point to destination point
						dij[p.a] = dij[f.a] + p.c;
						p.c = dij[p.a];
						Q.push(p);
					}
				}
			}
		}

		printf("%d\n", ans);
	}
}