#include <stdio.h>
#include <algorithm>

using namespace std;

int d[505][505];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	char out[][20] = { {"Stay here" },{ "Enjoy other party" } };

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);


		printf("%s\n", out[d[a][b] <= c]);
	}

}