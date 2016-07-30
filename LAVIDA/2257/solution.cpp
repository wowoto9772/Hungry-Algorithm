#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

char str[43][43];
bool chk[43][43];

int dr[] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dc[] = { -1, 1, -1, 0, 1, -1, 0, 1 };

int main() {

	int n;
	int tc = 0;

	while (scanf("%d", &n) == 1) {

		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			for (int j = 0; j < n; j++)chk[i][j] = false;
		}

		queue <ele> q;

		int x = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (str[i][j] == '1' && !chk[i][j]) {

					x++;

					q.emplace(i, j);

					while (!q.empty()) {
						ele f = q.front(); q.pop();
						for (int k = 0; k < 8; k++) {
							ele g = { f.r + dr[k], f.c + dc[k] };
							if (g.r < 0 || g.c < 0 || g.r >= n || g.c >= n)continue;
							if (chk[g.r][g.c])continue;
							if (str[g.r][g.c] == '0')continue;
							chk[g.r][g.c] = true;
							q.emplace(g);
						}
					}
				}
			}
		}

		printf("Case #%d: %d\n", ++tc, x);

	}

}