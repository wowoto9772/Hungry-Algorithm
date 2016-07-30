#include <stdio.h>
#include <limits.h>

#include <queue>
#include <vector>

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
		return c < A.c;
	}
};

bool chk[100003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	priority_queue <ele> q;
	vector < vector <ele> > lnk;

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		lnk[a].emplace_back(b, c);
		lnk[b].emplace_back(a, c);

	}

	int s, a;
	scanf("%d %d", &s, &a);

	q.emplace(s, INT_MAX);

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (chk[f.a])continue;

		chk[f.a] = true;

		if (f.a == a) {
			printf("%d\n", f.c);
			break;
		}

		for (int j = 0; j < lnk[f.a].size(); j++) {
			ele g = lnk[f.a][j];
			if (chk[g.a])continue;
			g.c = min(g.c, f.c);
			q.emplace(g);
		}

	}

}