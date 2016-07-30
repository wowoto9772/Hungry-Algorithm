#include <stdio.h>
#include <algorithm>

using namespace std;

#define Max 987654321

int d[103][103];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = Max;
			if (i == j)d[i][j] = 0;
		}
	}

	int m;
	scanf("%d", &m);
	
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (d[a][b] > c)d[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", d[i][j]);
		}printf("\n");
	}

}