#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <algorithm>

#include <queue>

using namespace std;

class ele {
public:

	int i, j, k;

	ele() {}
	ele(int _i, int _j, int _k) {
		i = _i, j = _j, k = _k;
	}

	bool operator<(const ele &A)const {
		return k < A.k;
	}
};

#define ll long long

int e[23][23], o[23][23], c[23][23];

int main() {

	int n;
	scanf("%d", &n);

	priority_queue <ele> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &o[i][j]);
			c[i][j] = o[i][j];
			if (i < j)q.emplace(i, j, o[i][j]);
		}
	}

	memcpy(e, o, sizeof(e));

	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (e[a][k] == -1 || e[k][b] == -1)continue;
				if (e[a][b] == -1)e[a][b] = e[a][k] + e[k][b];
				else
					e[a][b] = min(e[a][b], e[a][k] + e[k][b]);
			}
		}
	}

	bool imp = false;
	for (int i = 1; !imp && i <= n; i++)for (int j = 1; !imp && j <= n; j++)if (e[i][j] != c[i][j])imp = true;

	if (imp) {
		printf("-1\n");
		return 0;
	}

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		int i = f.i, j = f.j;

		if (o[i][j] == -1)continue;

		memcpy(e, o, sizeof(e));

		e[i][j] = e[j][i] = -1;

		for (int k = 1; k <= n; k++) {
			for (int a = 1; a <= n; a++) {
				for (int b = 1; b <= n; b++) {
					if (e[a][k] == -1 || e[k][b] == -1)continue;
					if (e[a][b] == -1)e[a][b] = e[a][k] + e[k][b];
					else
						e[a][b] = min(e[a][b], e[a][k] + e[k][b]);
				}
			}
		}

		bool flag = false;

		for (int a = 1; !flag && a <= n; a++) {
			for (int b = 1; !flag && b <= n; b++) {
				if (e[a][b] != c[a][b]) {
					flag = true;
				}
			}
		}

		if (!flag)o[i][j] = o[j][i] = -1;

	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (o[i][j] != -1)ans += o[i][j];
		}
	}

	printf("%d\n", ans);

}