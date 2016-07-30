#include <stdio.h>

int b[10][10];

int main() {

	b[0][0] = 1;
	for (int i = 1; i <= 8; i++) {
		b[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	// mCk + mCk+1 + mCk+2 + mCm
	// nCm

	int s = 0;
	for (int i = k; i <= m; i++) {
		s += b[m][i] * b[n - m][m - i];
	}

	int p = b[n][m];

	printf("%.10lf\n", (double)s / p);

}