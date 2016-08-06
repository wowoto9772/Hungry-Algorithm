#include <stdio.h>

int t[303];
int w[303];

int main() {

	for (int i = 1; i <= 302; i++) {
		t[i] = t[i - 1] + i;
	}

	for (int i = 1; i <= 300; i++) {
		w[i] = w[i - 1] + i * t[i + 1];
	}

	int x;
	scanf("%d", &x);

	while (x--) {

		int y;
		scanf("%d", &y);

		printf("%d\n", w[y]);

	}

}