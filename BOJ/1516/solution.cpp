#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class ele {
public:
	ele() {}
	ele(int a, int b) { v = a, c = b; }
	int v, c;
	bool operator<(const ele &A)const {
		return c > A.c;
	}
};

int t[503], in[503], fin[503];
bool ended[503];

int main() {

	int n;
	scanf("%d", &n);

	vector < vector <int> > nxt;
	nxt.resize(n + 1);

	priority_queue <ele> q;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);

		int v;
		while (scanf("%d", &v) == 1 && v >= 1) {
			nxt[v].push_back(i);
			in[i]++;
		}

		if (!in[i]) {
			q.emplace(i, t[i]);
		}

	}

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (ended[f.v])continue;
		
		ended[f.v] = true;
		fin[f.v] = f.c;

		for (int i = 0; i < nxt[f.v].size(); i++) {
		
			int k = nxt[f.v][i];
			in[k]--;

			if (!in[k]) {
				q.emplace(k, f.c + t[k]);
			}
		}

	}

	for (int i = 1; i <= n; i++)printf("%d\n", fin[i]);

}