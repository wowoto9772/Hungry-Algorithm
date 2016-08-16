#include <stdio.h>

int n;
int a[10];
char *x = " +-";

void Search(int c) {

	if (c == n) {

		int v = 0;

		int t = 1;

		int p = 1;

		for (int i = 2; i <= n; i++) {

			if (a[i - 1] == 0) {

				t = t * 10 + i;

			}
			else {

				if (p == 1)v += t;
				else
					v -= t;

				t = i;

				p = a[i - 1];

			}

		}

		if (t) {
			if (p == 1)v += t;
			else
				v -= t;
		}

		if (v == 0) {
			for (int i = 1; i <= n; i++) {
				printf("%d", i);
				if (i + 1 <= n)printf("%c", x[a[i]]);
			}printf("\n");
		}

		return;
	}

	for (int i = 0; i < 3; i++) {

		a[c] = i;

		Search(c + 1);

	}

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		scanf("%d", &n);

		Search(1);

		printf("\n");

	}

}