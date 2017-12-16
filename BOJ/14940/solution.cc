#include <cstdio>
#include <queue>

using namespace std;

class ele {
public:
	int r, c;
	ele() {}
	ele(int _r, int _c) {
		r = _r, c = _c;
	}
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int e[1003][1003];
int t[1003][1003];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	queue < ele > q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &e[i][j]);
			if (e[i][j] == 2) {
				q.emplace(i, j);
			}
			else {
				if (e[i][j] != 0)t[i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		ele f = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ele g = { f.r + dr[i], f.c + dc[i] };
			if (g.r < 1 || g.r > n || g.c < 1 || g.c > m)continue;
			if (t[g.r][g.c] != -1)continue;
			q.push(g);
			t[g.r][g.c] = t[f.r][f.c] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", t[i][j]);
		}puts("");
	}

}