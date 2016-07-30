#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int m;
		scanf("%d", &m);

		int q;
		scanf("%d", &q);

		while (q--) {

			int c, d;
			scanf("%d %d", &c, &d);

			m += c * d;

		}

		printf("%d\n", m);

	}

}