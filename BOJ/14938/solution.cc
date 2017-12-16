#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1000000007;

int c[103];
int d[103][103];

int main() {

	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 1; i <= n; i++)scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)d[i][j] = inf;
		d[i][i] = 0;
	}

	while (r--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (d[a][b] > c)d[a][b] = d[b][a] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}

	int y = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] <= m)x += c[j];
		}
		if (y < x)y = x;
	}

	printf("%d\n", y);

}