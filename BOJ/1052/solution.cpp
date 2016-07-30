#include <stdio.h>

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int x = 0;

	while (true) {

		int c = 0;

		for (int i = n + x; i > 0; i >>= 1) {
			c += 1 & i;
		}

		if (c <= k) {
			printf("%d\n", x);
			break;
		}

		x++;
	}

}