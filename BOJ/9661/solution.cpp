#include <stdio.h>

int main() {

	long long k;
	scanf("%lld", &k);

	k %= 5;

	if (k == 0 || k == 2)printf("CY\n");
	else
		printf("SK\n");

}