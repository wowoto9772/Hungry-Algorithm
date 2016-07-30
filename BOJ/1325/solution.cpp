#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int in[10003];
int cnt[10003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector <int> > lnk;
	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {

		int a, b;
		scanf("%d %d", &a, &b);

		lnk[b].push_back(a);

	}

	queue <int> q;

	for (int i = 1; i <= n; i++) {

		vector <bool> chk(n + 1);

		q.push(i);

		chk[i] = true;

		while (!q.empty()) {

			int f = q.front(); q.pop();

			for (int j = 0; j < lnk[f].size(); j++) {

				int g = lnk[f][j];

				if (!chk[g]) {

					cnt[i]++;

					chk[g] = true;
					q.push(g);

				}

			}

		}

	}


	vector <int> p;
	int c = -1;

	for (int i = 1; i <= n; i++) {
		if (c < cnt[i]) {
			c = cnt[i];
			p.clear();
			p.push_back(i);
		}
		else if (c == cnt[i]) {
			p.push_back(i);
		}
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < p.size(); i++)printf("%d ", p[i]);

} // cycle인 입력이 존재.