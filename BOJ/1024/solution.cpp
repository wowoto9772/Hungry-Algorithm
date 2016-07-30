#include <stdio.h>

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	n <<= 1;

	for (int i = k; i <= 100; i++) {
		if (n%i)continue;

		int x = n / i;

		// a + (a + i - 1) = x

		int y = x + (1 - i);

		if (y % 2)continue;
		y >>= 1;

		if (y >= 0) {
			for (int j = y; j < y + i; j++)printf("%d ", j);
			return 0;
		}
	}

	printf("-1\n");

}