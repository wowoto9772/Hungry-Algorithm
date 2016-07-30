#include <stdio.h>

int main() {

	int h, m, s;
	scanf("%d %d %d", &h, &m, &s);

	int t = h * 3600 + m * 60 + s;

	int k;
	scanf("%d", &k);

	while (k--) {
		int a;
		scanf("%d", &a);

		if (a == 3)printf("%d %d %d\n", t / 3600, (t % 3600) / 60, t % 60);
		else if (a == 2) {
			int b;
			scanf("%d", &b);

			t -= b;
		}
		else {
			int b;
			scanf("%d", &b);

			t += b;
		}

		while (t < 0)t += 3600 * 24;
		t %= 3600 * 24;
	}

}