#include <stdio.h>
#include <algorithm>

using namespace std;

class rect {
public:
	int bx, by, tx, ty;
}e[2];

bool met(int a, int b, int c, int d) {
	return !(b <= c || d <= a);
}

int main() {

	int n = 4;
	while (n--) {

		for (int i = 0; i < 2; i++)scanf("%d %d %d %d", &e[i].bx, &e[i].by, &e[i].tx, &e[i].ty);

		int x[4] = { e[0].bx, e[1].bx, e[0].tx, e[1].tx };
		int y[4] = { e[0].by, e[1].by, e[0].ty, e[1].ty };

		sort(x, x + 4);
		sort(y, y + 4);

		char a = 0;

		for (int i = 0; !a && i < 3; i++) {
			if (x[i] == x[i + 1])continue;
			for (int j = 0; !a && j < 3; j++) {
				if (y[j] == y[j + 1])continue;
				if (e[0].bx <= x[i] && x[i + 1] <= e[0].tx) {
					if (e[0].by <= y[j] && y[j + 1] <= e[0].ty) {
						if (e[1].bx <= x[i] && x[i + 1] <= e[1].tx) {
							if (e[1].by <= y[j] && y[j + 1] <= e[1].ty) {
								// rectangle
								a = 'a';
							}
						}
					}
				}
			}
		}

		if (!a) {

			if (e[0].tx == e[1].bx && e[0].ty == e[1].by ||
				e[0].tx == e[1].bx && e[0].by == e[1].ty ||
				e[0].bx == e[1].tx && e[0].ty == e[1].by ||
				e[0].bx == e[1].tx && e[0].by == e[1].ty) {
				// point
				a = 'c';
			}

			if (!a) {

				if (((e[0].by == e[1].ty || e[0].ty == e[1].by) && met(e[0].bx, e[0].tx, e[1].bx, e[1].tx)) ||
					((e[0].bx == e[1].tx || e[0].tx == e[1].bx) && met(e[0].by, e[0].ty, e[1].by, e[1].ty))) {
					// line
					a = 'b';
				}

				if (!a)a = 'd';

			}
		}

		printf("%c\n", a);

	}

}