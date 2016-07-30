#include <stdio.h>

int main()
{
	int n, T = 1;;
	while (scanf("%d", &n) == 1 && n){
		printf("%d. ", T++);
		if (n % 2)printf("odd ");
		else
			printf("even ");
		printf("%d\n", n / 2);
	}
}