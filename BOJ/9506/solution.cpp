#include <stdio.h>

int a[100003];

int main() {

	int n;
	while (scanf("%d", &n) == 1 && n > -1) {

		int top = 0;
		int c = 0;
		for (int i = 1; i < n; i++) {
			if (n%i)continue;
			c += i;
			a[top++] = i;
		}

		if (c == n) {
			printf("%d = ", n);
			for (int i = 0; i < top; i++) {
				if (i)printf(" + ");
				printf("%d", a[i]);
			}
		}
		else {
			printf("%d is NOT perfect.", n);
		}
		printf("\n");

	}

}