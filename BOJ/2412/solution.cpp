#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class ele {
public:
	int v, c;
	ele() { }
	ele(int a, int b) { v = a, c = b; }
};

int x[50003], y[50003];

int main() {

	int n, T;
	scanf("%d %d", &n, &T);

	map< int, map <int, int> > mp;
	vector < vector <int> > lnk;

	lnk.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		mp[x[i]][y[i]] = i;
	}

	for (int i = 0; i <= n; i++) {
		for (int a = x[i] - 2; a <= x[i] + 2; a++) {
			for (int b = y[i] - 2; b <= y[i] + 2; b++) {
				if (mp[a].find(b) != mp[a].end()) {
					if (i != mp[a][b]) {
						lnk[i].push_back(mp[a][b]);
					}
				}
			}
		}
	}

	queue <ele> q;
	vector <bool> chk(n + 1);

	q.emplace(0, 0);
	chk[0] = true;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (y[f.v] == T) {
			printf("%d\n", f.c);
			return 0;
		}

		for (int i = 0; i < lnk[f.v].size(); i++) {

			ele g = { lnk[f.v][i], f.c + 1 };

			if (chk[g.v])continue;

			chk[g.v] = true;
			q.emplace(g);

		}

	}

	printf("%d\n", -1);

}