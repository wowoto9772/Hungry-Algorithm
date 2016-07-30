#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector < int > > lnk;

int p[100003];
int dp[100003][5];

int dy(int c, int m) {

	if (dp[c][m] != -1)return dp[c][m];

	dp[c][m] = 0;

	for (int i = 0; i < lnk[c].size(); i++) {

		int n = lnk[c][i];

		if (p[c] == n)continue;

		p[n] = c;

		vector <int> a;

		for (int j = 1; j <= 4; j++) {
			if (m == j)continue;
			a.push_back(j + dy(n, j));
		}

		dp[c][m] += min({ a[0], a[1], a[2] });

	}

	return dp[c][m];

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

	lnk[0].push_back(1);

	dp[0][0] = -1;
	for (int i = 1; i <= n; i++)dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4] = -1;

	printf("%d\n", dy(0,0));

}

// https://ko.wikipedia.org/wiki/4%EC%83%89%EC%A0%95%EB%A6%AC