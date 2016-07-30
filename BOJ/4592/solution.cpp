#include <stdio.h>

int e[27];

int main() {

	int n;
	while (scanf("%d", &n) == 1 && n) {

		for (int i = 1; i <= n; i++) {

			scanf("%d", &e[i]);

		}

		printf("%d ", e[1]);

		for (int i = 2; i <= n; i++) {

			if (e[i - 1] == e[i])continue;
			else {
				printf("%d ", e[i]);
			}

		}

		printf("$\n");

	}

}