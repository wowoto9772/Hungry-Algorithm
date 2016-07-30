#include <stdio.h>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 54321

using namespace std;

char str[8];
int in[13];
int when[13];
int dp[1 << 14][2];

int n, m;

vector <int> nxt[13];

int dy(int s, int c) {

	if (s == (1 << n) - 1)return 0;

	if (dp[s][c] != -1)return dp[s][c];

	dp[s][c] = MAX;

	for (int i = m; i >= 1; i--) {
		for (int j = 0; j < nxt[i].size(); j++) {
			if ((1 << n) - 1 < nxt[i][j])continue;
			if ((nxt[i][j] & s) == nxt[i][j])continue;

			bool flag = true;

			for (int k = 0; k < n && flag; k++) {
				if ((nxt[i][j] & (1 << k)) == (1 << k)) {
					if ((in[k] & s) == in[k]) {
						if (!when[k] || when[k] == c || when[k] == 2 && !c) {
							// possible
						}
						else {
							flag = false;
						}
					}
					else {
						// impossible
						flag = false;
					}
				}
			}

			if (flag) {

				dp[s][c] = min(dp[s][c], 1 + dy(s | (nxt[i][j]), 1 ^ c));

			}

		}
	}

	if (dp[s][c] == MAX)dp[s][c] = min(dp[s][c], 1 + dy(s, 1 ^ c));

	return dp[s][c];

}

int main() {

	for (int i = 1; i < (1 << 12); i++) {
		int c = 0;
		for (int j = 0; j < 12; j++) {
			if (i&(1 << j))c++;
		}
		nxt[c].push_back(i);
	}

	while (scanf("%d %d", &n, &m) == 2) {

		if (n == -1 && n == m)break;

		for (int i = 0; i < (1 << n); i++)for (int j = 0; j <= 1; j++)dp[i][j] = -1;

		map <string, int> pars;

		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			pars[(string)str] = i;
		}

		for (int i = 1; i <= n; i++) {
			scanf("%s", str);

			int x = pars[(string)str] - 1;

			scanf(" %c", &when[x]);

			if (when[x] == 'B')when[x] = 0;
			else if (when[x] == 'S')when[x] = 2;
			else {
				when[x] = 1;
			}

			int c;
			scanf("%d", &c);

			in[x] = 0;

			for (int i = 1; i <= c; i++) {
				scanf("%s", str);

				int g = pars[(string)str] - 1;
				in[x] += (1 << g);

			}

		}

		// fall start
		printf("The minimum number of semesters required to graduate is %d.\n", dy(0, 1));

	}

}