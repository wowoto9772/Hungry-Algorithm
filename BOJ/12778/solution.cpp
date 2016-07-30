#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		char c;
		scanf("%d %c", &n, &c);

		if (c == 'C') {
			char x;
			for (int i = 1; i <= n; i++) {
				scanf(" %c", &x);

				printf("%d ", x - 'A' + 1);
			}
		}
		else {
			int x;
			for (int i = 1; i <= n; i++) {
				scanf("%d", &x);
				printf("%c ", x + 'A' - 1);
			}
		}

		printf("\n");
	}

}