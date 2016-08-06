#include <stdio.h>

int e[1003][6];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++)scanf("%d", &e[i][j]);
	}

	int ans = 0, x;

	for (int i = 1; i <= n; i++) {
		int c = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 5; k++) {
				if (e[i][k] == e[j][k]) {
					c++;
					break;
				}
			}
		}

		if (ans < c) {
			ans = c;
			x = i;
		}
	}

	printf("%d\n", x);

}