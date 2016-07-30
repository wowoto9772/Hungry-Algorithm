#include <stdio.h>
#include <queue>
#include <time.h>

using namespace std;

class ele {
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

int dr[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dc[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
bool chk[303][303] = { 0 };

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int l;
		scanf("%d", &l);

		for (int i = 0; i < l; i++)for (int j = 0; j < l; j++)chk[i][j] = false;

		int s, e;
		scanf("%d %d", &s, &e);

		int r, c;
		scanf("%d %d", &r, &c);

		queue <ele> q;
		queue <int> x;
		q.emplace(s, e);
		x.push(0);

		chk[s][e] = true;

		while (!q.empty()) {
			ele f = q.front(); q.pop();
			int ff = x.front(); x.pop();

			if (f.r == r && f.c == c) {
				printf("%d\n", ff);
				break;
			}

			for (int i = 0; i < 8; i++) {
				ele g = { f.r + dr[i], f.c + dc[i] };

				if (g.r < 0 || g.c < 0 || g.r >= l || g.c >= l)continue;

				if (chk[g.r][g.c])continue;

				chk[g.r][g.c] = true;

				q.emplace(g);
				x.push(ff + 1);
			}
		}

	}

}