#include <stdio.h>


int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	if (r >= 3) {
		if (c < 5)printf("%d", c);
		else if (c < 7)printf("4");
		else
			printf("%d", c - 2);
	}
	else if (r == 2) {
		if (c < 3)printf("1");
		else if (c < 5)printf("2");
		else if (c < 7)printf("3");
		else
			printf("4");
	}
	else if (r == 1) {
		printf("1");
	}

}