#include <stdio.h>

int e[103][103];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &e[i][j]);
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int a;
			scanf("%d", &a);
			e[i][j] += a;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", e[i][j]);
		}printf("\n");
	}

}