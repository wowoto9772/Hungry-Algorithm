#include <stdio.h>

char str[203];

int main() {

	int c = 0;
	while (fgets(str, 200, stdin)) {
		c++;
	}

	printf("%d\n", c);

}