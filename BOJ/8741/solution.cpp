#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	// 1 + 2 + ... + 2^n-1
	// S = (2^n-1) * (1 + 2^n-1) / 2
	// S = (2^n-1) * (2^n) / 2
	// S = (2^n-1)(2^(n-1))
	// 2^n-1 = 1111...1 (count(1) = n)
	// 2^(n-1) == 1000...0 (count(0) = n-1)

	for (int i = 1; i <= n; i++)printf("1");
	for (int i = 1; i <= n - 1; i++)printf("0");
	printf("\n");
}