#include <stdio.h>

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	n -= n % 100;

	for (int i = 0; i <= 99; i++) {
		if (n%k)n++;
		else {
			printf("%02d\n", n % 100);
			break;
		}
	}

}