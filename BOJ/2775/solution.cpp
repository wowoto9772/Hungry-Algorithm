#include <stdio.h>

int f[16][16];

int main() {

	for (int i = 1; i <= 14; i++) {
		f[1][i] = f[1][i - 1] + i;
	}

	for (int i = 2; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			for (int k = 1; k <= j; k++) {
				f[i][j] += f[i - 1][k];
			}
		}
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int k, n;
		scanf("%d %d", &k, &n);

		printf("%d\n", f[k][n]);

	}

}