#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int d[53][53];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)d[i][j] = INT_MAX / 3;
	
	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		
		if (a == -1)break;

		d[a][b] = d[b][a] = 1;

	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	vector <int> p;
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++) {

		int cmp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			cmp = max(cmp, d[i][j]);
		}

		if (ans > cmp) {
			p.clear();
			ans = cmp;
			p.push_back(i);
		}
		else if (ans == cmp)p.push_back(i);
	}

	sort(p.begin(), p.end());

	printf("%d %d\n", ans, p.size());

	for (int i = 0; i < p.size(); i++)printf("%d ", p[i]);

}