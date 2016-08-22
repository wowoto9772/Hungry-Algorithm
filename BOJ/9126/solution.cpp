#include <stdio.h>

#include <limits.h>

#include <functional>

#include <queue>
#include <vector>

#include <algorithm>

using namespace std;

#define c first
#define v second

int h[103]; // node's height
int d[103];

int main()
{

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, e;
		scanf("%d %d", &n, &e);

		vector < vector < pair <int, int> > > lnk;
		lnk.resize(n + 1);

		vector <int> x;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &h[i]);
			x.push_back(h[i]);
		}

		for (int i = 1; i <= e; i++) {

			int a, b, cc;
			scanf("%d %d %d", &a, &b, &cc);

			lnk[a].emplace_back(cc, b);
			lnk[b].emplace_back(cc, a);
		}

		sort(x.begin(), x.end());
		x.resize(distance(x.begin(), unique(x.begin(), x.end())));

		int l = 0, r = 1000000007, m;

		int dx, dh;

		while (l <= r) {

			m = (l + r) / 2;

			bool flag = false;

			for (int i = 0; i < x.size(); i++) {

				if (x[i] <= h[1] && h[1] <= x[i] + m) {

					for (int j = 1; j <= n; j++)d[j] = INT_MAX;

					d[1] = 0;

					int mh = x[i];
					int Mh = x[i] + m;

					priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > q;
					q.emplace(0, 1);

					while (!q.empty()) {

						pair <int, int> f = q.top(); q.pop();

						if (d[f.v] < f.c)continue;

						for (int i = 0; i < lnk[f.v].size(); i++) {

							pair <int, int> g = lnk[f.v][i];
							g.c += f.c;

							if (mh > h[g.v] || Mh < h[g.v])continue;

							if (d[g.v] > g.c) {

								d[g.v] = g.c;
								q.emplace(g);

							}
						}
					}

					if (d[n] != INT_MAX) {
						flag = true;
						break;
					}
				}
			}

			if (flag) {
				dx = d[n], dh = m;
				r = m - 1;
			}
			else if (!flag) {
				l = m + 1;
			}
		}

		printf("%d %d\n", dh, dx);
	}
}