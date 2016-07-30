#include <stdio.h>

bool mod[1000003];

int main() {

	int n;
	scanf("%d", &n);

	int d = 0;
	int c = 0;

	while (true) {

		d *= 10;
		d++;
		d %= n;
		c++;
		if (mod[d]) {
			printf("-1\n"); return 0;
		}
		else if (d == 0)break;

		mod[d] = true;
	}

	printf("%d\n", c);

}