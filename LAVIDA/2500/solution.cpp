#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

class ele {
public:
	int v, i;
	ele() {}
	ele(int a, int b) { v = a, i = b; }
};

char boss[103];
char lo[103], hi[103];

vector <int> lnk[203];

int dp[203][2];
bool flag = false;

int dy(int c, int x) {

	if (dp[c][x] != -1)return dp[c][x];

	dp[c][x] = 0;

	if (!x) {

		for (int j = 0; j < lnk[c].size(); j++) {

			int i = lnk[c][j];

			dp[c][x] += max(1 + dy(i, 1), dy(i, 0));

		}

	}
	else {

		for (int j = 0; j < lnk[c].size(); j++) {
			int i = lnk[c][j];
			dp[c][x] += dy(i, 0);
		}

	}

	return dp[c][x];

}

int main() {

	lnk[0].push_back(1);

	int n;
	while (scanf("%d", &n) == 1 && n) {

		scanf("%s", boss);

		int top = 1;

		map <string, int> mp;
		mp[string(boss)] = 1;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i][1] = -1;
			lnk[i].clear();
		}

		for (int i = 1; i < n; i++) {

			scanf("%s %s", lo, hi);

			int l, h;
			if (!mp[lo])mp[lo] = ++top;
			l = mp[lo];
			if (!mp[hi])mp[hi] = ++top;
			h = mp[hi];

			lnk[h].push_back(l);

		}

		flag = false;

		int ans = max(dy(1, 0), 1 + dy(1, 1));

		queue <ele> q;
		
		q.emplace(0, 0);

		while (!q.empty() && !flag) {

			ele f = q.front(); q.pop();

			if (f.i == 0) {

				for (int i = 0; i < lnk[f.v].size(); i++) {

					int g = lnk[f.v][i];

					if (dp[g][1] + 1 == dp[g][0]) {

						flag = true;

					}
					else {

						if (dp[g][1] + 1 > dp[g][0]) {
							q.emplace(g, 1);
						}
						else {
							q.emplace(g, 0);
						}

					}

				}

			}else{
			
				for (int i = 0; i < lnk[f.v].size(); i++) {

					int g = lnk[f.v][i];

					q.emplace(lnk[f.v][i], 0);

				}

			}
		}

		printf("%d %s\n", ans, flag ? "No" : "Yes");

	}

}