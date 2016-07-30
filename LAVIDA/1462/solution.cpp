#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class ele {
public:
	int v, c;
	ele() {}
	ele(int a, int b) { v = a, c = b; }
	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

int in[10003];
int t[10003];

bool chk[10003];

int main() {

	int n;
	scanf("%d", &n);

	vector < vector <int> > nxt;

	nxt.resize(n + 1);

	for (int i = 1; i <= n; i++) {

		scanf("%d", &t[i]);

		int c;
		scanf("%d", &c);

		for (int j = 1; j <= c; j++) {

			int a;
			scanf("%d", &a);
			in[i]++;
			nxt[a].push_back(i);

		}
	}

	priority_queue <ele> q;

	int fin = 0;

	for (int i = 1; i <= n; i++) {
		if (!in[i])q.emplace(i, t[i]);
	}

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (chk[f.v])continue;
		chk[f.v] = true;

		fin = max(fin, f.c);

		for (int j = 0; j < nxt[f.v].size(); j++) {
			int m = nxt[f.v][j];
			in[m]--;
			if (!in[m])q.emplace(m, f.c + t[m]);
		}

	}

	printf("%d\n", fin);

}