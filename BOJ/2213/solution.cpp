#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector < vector <int> > lnk;

int x[10003], p[10003];

int dp[10003][2];

int dy(int c, int s) {

	if (dp[c][s] != -1)return dp[c][s];

	dp[c][s] = 0;

	if (s) {

		for (int i = 0; i < lnk[c].size(); i++) {

			int n = lnk[c][i];

			if (p[c] == n)continue;

			p[n] = c;

			dp[c][s] += dy(n, 0);

		}

	}
	else {

		for (int i = 0; i < lnk[c].size(); i++) {

			int n = lnk[c][i];

			if (p[c] == n)continue;

			p[n] = c;

			dp[c][s] += max(dy(n, 0), x[n] + dy(n, 1));

		}

	}

	return dp[c][s];

}

class ele {
public:
	int c, s;
	ele() {}
	ele(int a, int b) { c = a, s = b; }
};

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		dp[i][0] = dp[i][1] = -1;
	}

	lnk.resize(n + 1);

	for (int i = 1; i < n; i++) {

		int a, b;
		scanf("%d %d", &a, &b);

		lnk[a].push_back(b);
		lnk[b].push_back(a);

	}

	printf("%d\n", max(dy(1, 0), x[1] + dy(1, 1)));

	vector <int> out;

	queue <ele> q;

	if (dy(1, 0) > x[1] + dy(1, 1)) {
		q.emplace(1, 0);
	}
	else {
		q.emplace(1, 1);
	}

	while (!q.empty()) {

		ele f = q.front(); q.pop();

		if (f.s)out.push_back(f.c);

		for (int i = 0; i < lnk[f.c].size(); i++) {
			int m = lnk[f.c][i];

			if (p[f.c] == m)continue;

			if (f.s) {
				q.emplace(m, 0);
			}
			else {
				if (dp[m][0] > x[m] + dp[m][1]) {
					q.emplace(m, 0);
				}
				else {
					q.emplace(m, 1);
				}
			}
		}

	}

	sort(out.begin(), out.end());

	for (int i = 0; i < out.size(); i++)printf("%d ", out[i]);

}