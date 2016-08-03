#include <stdio.h>

int e[1003][1003];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < j)scanf("%d", &e[i][j]);
			else
				scanf("%*d");
		}
	}

	if (n > 2) {

		for (int j = 1; j < n - 1; j++) {
			int _2a = e[j][j + 1] + e[j][j + 2] - e[j + 1][j + 2];
			e[j][j] = _2a >> 1;
		}

		for (int j = n - 1; j <= n; j++) {
			e[j][j] = e[1][j] - e[1][1];
		}

	}
	else {
		e[1][1] = e[2][2] = e[1][2] >> 1;
	}

	for (int i = 1; i <= n; i++)printf("%d ", e[i][i]);

}