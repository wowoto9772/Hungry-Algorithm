#include <stdio.h>

int x[103];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	while (m--) {

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		for (int i = a; i <= b; i++)x[i] = c;

	}

	for (int i = 1; i <= n; i++)printf("%d ", x[i]);

}