#include <stdio.h>
#include <queue>

using namespace std;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

class ele{
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

char str[103][103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	bool chk[103][103] = { 0 };

	int c = 0, d = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j])continue;

			c++;

			queue <ele> q;
			q.emplace(i, j);

			while (!q.empty()) {

				ele f = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {

					ele g = { f.r + dr[k], f.c + dc[k] };

					if (g.r < 0 || g.c < 0 || g.r >= n || g.c >= n)continue;

					if (chk[g.r][g.c])continue;

					if (str[f.r][f.c] == str[g.r][g.c]) {
						chk[g.r][g.c] = true;
						q.emplace(g);
					}
				}

			}

		}
	}

	bool chk2[103][103] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk2[i][j])continue;

			d++;

			queue <ele> q;
			q.emplace(i, j);

			while (!q.empty()) {

				ele f = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {

					ele g = { f.r + dr[k], f.c + dc[k] };

					if (g.r < 0 || g.c < 0 || g.r >= n || g.c >= n)continue;

					if (chk2[g.r][g.c])continue;

					if (str[f.r][f.c] == str[g.r][g.c]) {
						chk2[g.r][g.c] = true;
						q.emplace(g);
					}
					else {
						if (str[f.r][f.c] == 'R' && str[g.r][g.c] == 'G' ||
							str[f.r][f.c] == 'G' && str[g.r][g.c] == 'R' ) {

							chk2[g.r][g.c] = true;
							q.emplace(g);

						}
					}
				}

			}

		}
	}

	printf("%d %d\n", c, d);

}