#include <stdio.h>

#include <algorithm>

using namespace std;

int e[53];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)scanf("%d", &e[i]);

	if (n == 1) {
		printf("A");
	}
	else if (n == 2) {
		if (e[1] == e[2])printf("%d", e[2]);
		else
			printf("A");
	}
	else {

		int a, b;

		if (e[2] != e[1])a = (e[3] - e[2]) / (e[2] - e[1]);
		else
			a = 1;

		b = e[2] - e[1] * a;

		for (int i = 1; i < n; i++) {
			if (e[i] * a + b != e[i + 1]) {
				printf("B");
				return 0;
			}
		}

		printf("%d\n", e[n] * a + b);

	}

}