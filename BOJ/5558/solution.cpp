#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	int h, w, c;
	ele() {}
	ele(int a, int b, int m) { h = a, w = b, c = m; }
};

int chk[1003][1003];
char str[1003][1003];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);

	ele s;

	for (int i = 0; i < h; i++) {
		scanf("%s", str[i]);
		for (int j = 0; j < w; j++) {
			if (str[i][j] == 'S') {
				s = { i, j, 0 };
			}
		}
	}

	for (int i = 1; i <= n; i++) {

		queue <ele> q;
		q.emplace(s);

		chk[s.h][s.w] = i;

		while (!q.empty()) {

			ele f = q.front(); q.pop();
			if (str[f.h][f.w] == '0' + i) {
				if (i == n) {
					printf("%d\n", f.c);
				}
				else {
					s = f;
				}
				break;
			}else{

				for (int j = 0; j < 4; j++) {
					ele g = { f.h + dr[j], f.w + dc[j], f.c + 1 };

					if (g.h < 0 || g.w < 0 || g.h >= h || g.w >= w)continue;

					if (str[g.h][g.w] == 'X')continue;

					if (chk[g.h][g.w] != i) {
						chk[g.h][g.w] = i;
						q.emplace(g);
					}
				}
				
			}
		}
	}

}