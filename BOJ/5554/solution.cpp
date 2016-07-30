#include <stdio.h>

int main() {

	int c = 0;

	for (int i = 0; i < 4; i++) {
		int a;
		scanf("%d", &a);

		c += a;
	}

	printf("%d\n%d\n", c / 60, c % 60);
}