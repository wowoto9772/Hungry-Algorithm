#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

bool chk[103][103];

char str[103][103];
char keys[30];

int hasd[103][103];

class ele {
public:
	int r, c;
	ele() {}
	ele(int a, int b) { r = a, c = b; }
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int r, c;
		scanf("%d %d", &r, &c);

		for (int i = 0; i < r; i++) {
			scanf("%s", str[i]);
			for (int j = 0; j < c; j++) {
				if (str[i][j] == '$')hasd[i][j] = 1;
				else
					hasd[i][j] = 0;
			}
		}

		bool hask[26] = { 0 };

		scanf("%s", keys);
		if (strcmp(keys, "0")) {
			int s = strlen(keys);
			for (int i = 0; i < s; i++) {
				hask[keys[i] - 'a'] = true;
			}
		}

		int ans = 0;

		while (true) {

			int getk = 0;

			for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)chk[i][j] = false;

			queue <ele> q;

			for (int j = 0; j < c; j++) {
				if (str[0][j] != '*'){
					chk[0][j] = true;
					q.emplace(0, j);
				}
				if (str[r-1][j] != '*'){
					chk[r - 1][j] = true;
					q.emplace(r - 1, j);
				}
			}

			for (int j = 1; j < r - 1; j++) {
				if (str[j][0] != '*'){
					chk[j][0] = true;
					q.emplace(j, 0);
				}
				if (str[j][c - 1] != '*'){
					chk[j][c - 1] = true;
					q.emplace(j, c - 1);
				}
			}

			while (!q.empty()) {

				ele f = q.front(); q.pop();

				if (str[f.r][f.c] >= 'A' && str[f.r][f.c] <= 'Z') {
					// can not proceed
					if (!hask[str[f.r][f.c] - 'A'])continue;
				}
				else if (str[f.r][f.c] >= 'a' && str[f.r][f.c] <= 'z') {
					int curkey = str[f.r][f.c] - 'a';
					if (!hask[curkey]) {
						getk++;
						hask[curkey] = true;
					}
				}

				if (hasd[f.r][f.c]) {
					ans++;
					hasd[f.r][f.c] = 0;
				}

				for (int i = 0; i < 4; i++) {

					ele g = { f.r + dr[i], f.c + dc[i] };

					if (g.r < 0 || g.r >= r || g.c < 0 || g.c >= c)continue;
					if (chk[g.r][g.c])continue;

					if (str[g.r][g.c] == '*')continue;

					chk[g.r][g.c] = true;

					q.emplace(g);
				}

			}

			if (!getk) {
				break;
			}

		}

		printf("%d\n", ans);

	}

}