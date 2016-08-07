#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int c = 0;

	for (int i = 1; i <= n; i++) {

		int x;
		scanf("%d", &x);

		c += (x - 1) % 2;

		printf("%d\n", (c & 1) ? 1 : 2);

	}

}