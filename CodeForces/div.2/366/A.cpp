#include <stdio.h>

char o[2][23] = { "I hate ", "I love " };

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		if (i != 0)printf("that ");
		printf("%s", o[i & 1]);
	}

	printf("it\n");

}