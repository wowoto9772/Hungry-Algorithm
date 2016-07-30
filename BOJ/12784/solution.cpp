#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int p[1003];
int dp[1003];

class ele {
public:
	int a, c;
	ele() {}
	ele(int a_, int c_) { a = a_, c = c_; }
};

int dy(int c, const vector < vector <ele> > &lnk) {

	if (dp[c] != -1)return dp[c];

	dp[c] = 0;

	bool isleaf = true;

	for (int j = 0; j < lnk[c].size(); j++) {

		ele f = lnk[c][j];

		if (p[c] == f.a)continue;

		isleaf = false;

		p[f.a] = c;

		dp[c] += min(dy(f.a, lnk), f.c);

	}

	if (isleaf)dp[c] = INT_MAX / 2;

	return dp[c];

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n, m;
		scanf("%d %d", &n, &m);

		if (n == 1)printf("0\n");
		else {

			for (int i = 1; i <= n; i++)dp[i] = -1, p[i] = 0;

			vector < vector <ele> > lnk;

			lnk.resize(n + 1);

			for (int i = 1; i <= m; i++) {

				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);

				lnk[a].emplace_back(b, c);
				lnk[b].emplace_back(a, c);

			}

			printf("%d\n", dy(1, lnk));

		}

	}
}