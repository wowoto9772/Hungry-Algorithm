#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int x[3003], y[3003], r[3003];
bool used[3003];

bool meet(int a, int b) {
	
	int ret = (x[a] - x[b]) * (x[a] - x[b]);
	ret += (y[a] - y[b]) * (y[a] - y[b]);

	int cmp = (r[a] + r[b])*(r[a] + r[b]);

	return ret <= cmp;

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		vector < vector <int> > lnk;
		lnk.resize(n + 1);

		for (int i = 1; i <= n; i++)used[i] = false;

		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
			for (int j = 1; j < i; j++){
				if (meet(i, j)) {
					lnk[i].push_back(j);
					lnk[j].push_back(i);
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++) {

			if (!used[i]) {

				ans++;

				used[i] = true;

				queue <int> q;
				q.push(i);

				while (!q.empty()) {

					int f = q.front(); q.pop();

					for (int j = 0; j < lnk[f].size(); j++) {
						
						int a = lnk[f][j];

						if (used[a])continue;

						used[a] = true;

						q.push(a);

					}

				}
			}
		}

		printf("%d\n", ans);

	}

}