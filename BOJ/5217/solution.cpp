#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		printf("Pairs for %d: ", n);

		int k = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (i == (n - i))continue;
			if (k)printf(", ");
			printf("%d %d", i, n - i);
			k++;
		}printf("\n");

	}

}