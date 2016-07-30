#include <stdio.h>

int main()
{

	int k;
	scanf("%d", &k);

	printf("3\n1 1 %d 1\n", k + 1);

	return 0;
}

// 1*1*(k+1) + 1*(k+1)*1 = 2 * k + 2
// (1*(k+1)*1) + 1*1*1 = k + 2;
// 2k+2 - (k+2) = k