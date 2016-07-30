#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int x = 1;

		for (int i = 1; i; i+=x){
			for (int j = 1; j <= n - i; j++)printf(" ");
			for (int k = 1; k <= i; k++)printf("%d", k);
			for (int k = i - 1; k >= 1; k--)printf("%d", k);
			printf("\n");
			if (i == n)x *= -1;
		}
	}
}