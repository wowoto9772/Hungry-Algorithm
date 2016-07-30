#include <stdio.h>

int dig[36];

int main() {

	for (int i = 0; i < 10; i++)dig[i] = '0' + i;
	for (int i = 'A'; i <= 'Z'; i++)dig[10 + i - 'A'] = i;

	int n, b;
	scanf("%d %d", &n, &b);

	int rev[36];

	int top = 0;

	while (n) {
		rev[top++] = dig[n % b];
		n /= b;
	}

	for (int i = top - 1; i >= 0; i--)printf("%c", rev[i]);

}