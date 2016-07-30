#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char str[205][205];
bool hit[205][205];

int er[] = { 0, 0, -1, 1 };
int ec[] = { -1, 1, 0, 0 };

class ele {
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

char k_[7];

int main() {

	int r, c;

	scanf("%d %d %s", &c, &r, &k_);

	r = r * 2 + 1;
	c = c * 2 + 1;

	int s = strlen(k_);

	int k = 0;

	int ak = 0;
	for (int i = 0; i < s; i++) {
		if (k_[i] == '.') {
			if (i + 1 < s && (k_[i + 1] == '5')) {
				ak++;
			}
			break;
		}
		k = k * 10 + k_[i] - '0';
	}

	k = k * 2 + ak;

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	ele cur = { r - 1, k };
	ele src;

	int d = 0;

	int ans = 0;
	int flg = 0;

	int dr = -1, dc = -1;

	while (cur.r != r - 1 || cur.r == r - 1 && flg == 0) {

		ele nxt = { cur.r + dr, cur.c + dc };

		if (nxt.c < 0 || nxt.c >= c) {
			dc *= -1;
			continue;
		}
		else if (nxt.r < 0 || nxt.r >= r)
		{
			dr *= -1;
			continue;
		}

		bool isHit = false;

		if (str[cur.r][cur.c] == 'B') {
			if (!hit[cur.r][cur.c]) {

				isHit = true;
				src = cur;

			}
		}
		else {

			if ((nxt.r & 1) ^ (nxt.c & 1)) {

				if (cur.r & 1) {

					if (str[cur.r][nxt.c] == 'B') {

						if (!hit[cur.r][nxt.c]) {

							isHit = true;
							src = { cur.r, nxt.c };

						}

					}

				}
				else {

					if (str[nxt.r][cur.c] == 'B') {

						if (!hit[nxt.r][cur.c]) {

							isHit = true;
							src = { nxt.r, cur.c };

						}

					}

				}

			}

		}



		if (isHit) {

			hit[src.r][src.c] = true;
			ans++;

			queue <ele> q;
			q.emplace(src);

			while (!q.empty()) {

				ele f = q.front(); q.pop();

				for (int i = 0; i < 4; i++) {

					ele g = { f.r + er[i], f.c + ec[i] };

					if (g.r < 0 || g.r >= r || g.c < 0 || g.c >= c)continue;

					if (str[g.r][g.c] == '.') {

						g.r += er[i];
						g.c += ec[i];

						if (g.r < 0 || g.r >= r || g.c < 0 || g.c >= c)continue;

						if (!hit[g.r][g.c] && str[g.r][g.c] == 'B') {

							hit[g.r][g.c] = true;
							q.emplace(g);

						}

					}
				}
			}
		}

		if (cur.r == r - 1)flg++;
		cur = nxt;

	}

	printf("%d\n", ans);

}

/*
1 9 1
+-+
|B|
+.+
|B|
+.+
|B|
+.+
|B|
+-+
|B|
+-+
|B|
+-+
|B|
+-+
|B|
+-+
|B|
+-+
*/