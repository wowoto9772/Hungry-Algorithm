#include <stdio.h>

int main() {

	int v;
	scanf("%d", &v);

	int c = 0;

	while (v >= 10) {

		int nv = 1;
		while (v) {
			nv *= v % 10;
			v /= 10;
		}

		v = nv;

		c++;

	}

	printf("%d\n", c);

}