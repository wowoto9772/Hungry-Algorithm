#include <stdio.h>

#include <queue>

using namespace std;

vector < vector <int> > lnk;

bool d[103003];

class ele {
public:
	int a, c;

	ele() {}
	ele(int a_, int c_) {
		a = a_, c = c_;
	}
};

int main() {

	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);

	lnk.resize(n + m + 3);

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			int x;
			scanf("%d", &x);
			lnk[n + i].emplace_back(x);
			lnk[x].push_back(n + i);
		}
	}

	queue <ele> q;

	q.emplace(1, 0);
	d[1] = true;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (f.a == n) {
			printf("%d\n", ++f.c / 2 + 1);
			return 0;
		}

		for (int k = 0; k < lnk[f.a].size(); k++) {

			if (!d[lnk[f.a][k]]) {
				d[lnk[f.a][k]] = true;
				q.emplace(lnk[f.a][k], f.c + 1);
			}

		}

	}

	printf("-1\n");

}