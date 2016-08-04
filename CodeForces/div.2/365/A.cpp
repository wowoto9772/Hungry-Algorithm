#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	int m = 0, c = 0;

	while (t--) {

		int x, y;
		scanf("%d %d", &x, &y);

		if (x > y)m++;
		else if (x < y)c++;

	}

	if (m > c)printf("Mishka\n");
	else if (m < c)printf("Chris\n");
	else
		printf("Friendship is magic!^^\n");


}
