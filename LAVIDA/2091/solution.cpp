#include <stdio.h>

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) == 2 && m && n){
		if (m % 2)m++;
		m /= 2;
		m *= m;

		if (m%n)printf("NO\n");
		else
			printf("YES\n");
	}
}