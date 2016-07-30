#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ele {
public:
	int v, c;
	ele() {}
	ele(int a, int b) { v = a, c = b; }
};

int in[1003];

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)in[i] = 0;

		vector < vector <int> > nxt;
		nxt.resize(n + 1);

		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			nxt[a].push_back(b);
			in[b]++;
		}
		
		queue <ele> q;
		for (int i = 1; i <= n; i++)if (!in[i])q.emplace(i, 0);

		int ans = 0;

		while (!q.empty()) {

			ele f = q.front(); q.pop();
			ans = max(ans, f.c);

			for (int i = 0; i < nxt[f.v].size(); i++) {

				int x= nxt[f.v][i];

				in[x]--;
				if (!in[x]) {
					q.emplace(x, f.c + 1);
				}

			}

		}

		printf("%d\n", ++ans);

	}

}