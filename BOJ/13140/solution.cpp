#include <stdio.h>

int cnt(int v) {

	if (!v)return 1;

	int r = 0;

	while (v) {
		r++;
		v /= 10;
	}
}

int main() {

	int x;
	scanf("%d", &x);

	int s = cnt(x);

	if (s >= 7)printf("No Answer\n");
	else {

		// h 10000
		// e 1000
		// l 120
		// o 1001
		// w 10000
		// r 100
		// d 1

		for (int h = 1; h < 10; h++) {
			for (int e = 0; e < 10; e++) {
				if (h == e)continue;
				for (int l = 0; l < 10; l++) {
					if (h == l || e == l)continue;
					for (int r = 0; r < 10; r++) {
						if (h == r || e == r || l == r)continue;
						for (int o = 0; o < 10; o++) {
							if (o == h || o == e || o == l || o == r)continue;
							for (int w = 1; w < 10; w++) {
								if (w == h || w == e || w == l || w == r || w == o)continue;
								for (int d = 0; d < 10; d++) {
									if (d == h || d == e || d == l || d == r || d == o || d == w)continue;
									int k = h * 10000 + e * 1000 + l * 120 + r * 100 + o * 1001 + w * 10000 + d;
									if (k == x) {
										printf("  %d%d%d%d%d\n", h, e, l, l, o);
										printf("+ %d%d%d%d%d\n", w, o, r, l, d);
										printf("-------\n");
										printf("%7d\n", x);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}

		printf("No Answer\n");

	}

}