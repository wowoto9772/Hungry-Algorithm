#include <stdio.h>

int main() {

	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	a--, b--;

	int c = 1;

	while (a >> 1 != b >> 1) {
		c++;
		a >>= 1;
		b >>= 1;
	}

	printf("%d\n", c);

}