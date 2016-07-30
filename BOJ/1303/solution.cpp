#include <stdio.h>
#include <string.h>

#include <queue>

using namespace std;

class ele {
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

char str[103][103];
bool chk[103][103];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

	int r, c;
	scanf("%d %d", &c, &r);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	int w = 0, b = 0;

	queue <ele> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (chk[i][j])continue;

			q.emplace(i, j);
			chk[i][j] = true;

			int x = 1;

			while (!q.empty()) {

				ele f = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {

					ele g = { f.r + dr[k], f.c + dc[k] };

					if (g.r < 0 || g.r >= r || g.c < 0 || g.c >= c)continue;

					if (chk[g.r][g.c])continue;

					if (str[i][j] == str[g.r][g.c]) {
						chk[g.r][g.c] = true;
						q.emplace(g);
						x++;
					}

				}

			}

			if (str[i][j] == 'W')w += x*x;
			else
				b += x*x;
		}
	}

	printf("%d %d\n", w, b);

}