#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= 9; i++)printf("%d x %d = %d\n", n, i, n*i);
	}
}