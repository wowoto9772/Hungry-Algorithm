#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > lnk;

int dp[1000003][2];
int p[1000003];

int dy(int c, int x) {

	int &ret = dp[c][x];

	if (ret != -1)return ret;

	ret = 0;

	for (int i = 0; i < lnk[c].size(); i++) {

		int n = lnk[c][i];

		if (p[c] == n)continue;

		p[n] = c;

		if (!x)ret += dy(n, 1) + 1;
		else
			ret += min(dy(n, 0), 1 + dy(n, 1));

	}

	return ret;

}

int main() {

	int n;
	scanf("%d", &n);

	lnk.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)dp[i][0] = dp[i][1] = -1;

	printf("%d\n", min(dy(1, 0), 1 + dy(1, 1)));

}