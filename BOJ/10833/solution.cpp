#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int c = 0;

	for (int i = 1; i <= n; i++){
		int a, p;
		scanf("%d %d", &p, &a);
		c += a - a / p * p;
	}

	printf("%d\n", c);
}