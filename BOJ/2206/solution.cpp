#include <stdio.h>
#include <queue>

using namespace std;

class ele {
public:
	int r, c, g, m;
	ele() {}
	ele(int a, int b, int h, int o) { r = a, c = b, g = h, m = o; }
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

char str[1003][1003];
bool chk[1003][1003][2];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	queue <ele> q;

	q.emplace(0, 0, 0, 0);
	chk[0][0][0] = true;

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (f.r == r - 1 && f.c == c - 1) {
			printf("%d\n", f.m + 1);
			return 0;
		}

		for (int i = 0; i < 4; i++) {

			ele g = f;
			g.r += dr[i];
			g.c += dc[i];

			if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c)continue;
			if (chk[g.r][g.c][g.g])continue;

			g.m++;

			if (str[g.r][g.c] == '1') {
				if (!g.g) {
					g.g = 1;
					if (chk[g.r][g.c][g.g])continue;
					chk[g.r][g.c][g.g] = true;
					q.emplace(g);
				}
			}
			else {
				chk[g.r][g.c][g.g] = true;
				q.emplace(g);
			}

		}

	}

	printf("-1\n");

}