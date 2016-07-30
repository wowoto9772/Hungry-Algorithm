#include <stdio.h>

char X[] = { "ABCDGKMPSW" };

int main()
{
	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){
		int n;
		scanf("%d", &n);
		int c = n / 2;
		if (n % 2)c++;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int a = i > n + 1 - i ? n + 1 - i : i;
				int b = j > n + 1 - j ? n + 1 - j : j;
				if (a > b)a = b;
				int k = c - a;
				printf("%c", X[k]);
			}printf("\n");
		}if(T<t)printf("\n");
	}
}