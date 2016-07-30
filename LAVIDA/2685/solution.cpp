#include <stdio.h>

int dy(int w, int h, int p) {

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int r, c, p;

		char w;
		scanf("%d %d %c", &r, &c, &w);

		if (w == 'H')p = 1;
		else
			p = 0;

		printf("%d\n", dy(r, c, p));

	}

}