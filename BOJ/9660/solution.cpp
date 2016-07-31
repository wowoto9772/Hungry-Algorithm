#include <stdio.h>

int main() {

	long long a;
	scanf("%lld", &a);

	a %= 7;

	if (a == 0 || a == 2)printf("CY\n");
	else
		printf("SK\n");

}