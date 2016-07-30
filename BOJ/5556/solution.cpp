#include <stdio.h>
#include <algorithm>

using namespace std;

class point {
public:

	int x, y;
	point() {}
	point(int a, int b) { x = a, y = b; }

};

int main() {

	int n;
	scanf("%d", &n);

	if (n % 2) {
		// odd

		int m = (n + 1) / 2;
		int c = 1 + (m - 1) % 3;

		int q;
		scanf("%d", &q);

		while (q--) {

			int a, b;
			scanf("%d %d", &a, &b);

			int d = max(abs(a - m), abs(b - m)) % 3;

			d = 3 + c - d;
			d %= 3;

			if (d == 0)d = 3;

			printf("%d\n", d);

		}

	}
	else {
		// even

		int m = n / 2;
		int c = 1 + (m - 1) % 3;

		point x[] = { {m, m},{m, m + 1}, {m + 1, m}, {m + 1, m + 1} };

		int q;
		scanf("%d", &q);

		while (q--) {

			int a, b;
			scanf("%d %d", &a, &b);

			int dm = n + 1;
			for (int i = 0; i < 4; i++) {
				int d = max(abs(x[i].x - a), abs(x[i].y - b));
				dm = min(dm, d);
			}

			dm %= 3;

			dm = 3 + c - dm;
			dm %= 3;

			if (dm == 0)dm = 3;

			printf("%d\n", dm);
		}
	}

}