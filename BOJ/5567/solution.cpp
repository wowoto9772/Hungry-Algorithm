#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

class ele {
public:
	int v, l;
	ele() {}
	ele(int a, int b) { v = a, l = b; }
};

bool chk[505];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector < int > > lnk;
	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	chk[1] = true;

	int c = 0;

	queue < ele > q;

	q.emplace(1, 2);

	while (!q.empty()) {
		ele f = q.front(); q.pop();
		if (f.l) {
			for (int j = 0; j < lnk[f.v].size(); j++) {
				ele g = { lnk[f.v][j], f.l - 1 };
				if (chk[g.v])continue;
				c++;
				chk[g.v] = true;
				q.emplace(g);
			}
		}
	}

	printf("%d\n", c);

}