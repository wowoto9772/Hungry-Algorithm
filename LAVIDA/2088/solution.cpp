#include <stdio.h>

int main()
{
	int m, n, k;
	while (scanf("%d %d %d", &m, &n, &k) == 3 && m && n && k){
		m = (n - m + 1) * (m + n) / 2;

		if (m%k)printf("NO\n");
		else
			printf("YES\n");
	}
}