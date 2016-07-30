#include <stdio.h>

int main() {

	int a[2];
	int b[2];

	for (int i = 0; i < 2; i++)scanf("%d", &a[i]);
	for (int i = 0; i < 2; i++)scanf("%d", &b[i]);

	int s[] = { a[1] / b[0] + ((a[1] % b[0]) ? 1 : 0),
		b[1] / a[0] + ((b[1] % a[0]) ? 1 : 0) };

	if (s[0] > s[1])printf("PLAYER A");
	else if (s[0] < s[1])printf("PLAYER B");
	else
		printf("DRAW");

}