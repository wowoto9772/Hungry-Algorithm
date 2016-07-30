#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

#define mod 1000000007

#define ll long long

using namespace std;

int v[303];
vector <int> dv[1000003];
int dp[303][303];

int n;

// v[0] : 0
int dy(int c, int p) {

	if (c == n + 1)return 1;
	if (dp[c][p] != -1)return dp[c][p];

	int prev = dv[v[c - 1]][p];

	dp[c][p] = 0;

	for (int i = 0; i < dv[v[c]].size(); i++) {
		if (prev <= dv[v[c]][i]) {
			dp[c][p] += dy(c + 1, i);
			dp[c][p] %= mod;
		}
	}

	return dp[c][p];

}

int main() {

	dv[0].push_back(0);

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {

			scanf("%d", &v[i]);

			if (dv[v[i]].empty()) {

				vector <int> p, c;

				int x = v[i];

				for (int j = 2; j*j <= x; j++) {
					if (x%j)continue;
					p.push_back(j);
					c.push_back(0);

					while (!(x%j)) {
						c.back()++;
						x /= j;
					}
				}

				if (x != 1) {
					p.push_back(x);
					c.push_back(1);
				}

				queue <int> q, w;
				q.push(1);
				w.push(0);

				while (!q.empty()) {
					
					int f = q.front(); q.pop();
					int g = w.front(); w.pop();

					dv[v[i]].push_back(f);

					for (int j = g; j < p.size(); j++) {
						for (int k = 1; k <= c[j]; k++) {
							int h = f * pow(p[j], k);
							q.push(h);
							w.push(j + 1);
						}
					}

				}

				sort(dv[v[i]].begin(), dv[v[i]].end());
			}

			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < dv[v[i-1]].size(); j++) {
					dp[i][j] = -1;
				}
			}

		}

		printf("%d\n", dy(1, 0));

	}

}