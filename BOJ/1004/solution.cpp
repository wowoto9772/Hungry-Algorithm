#include <stdio.h>

class point {
public:
	int x, y, r;

	int operator - (const point &A)const {
		return (x - A.x)*(x - A.x) + (y - A.y)*(y - A.y);
	}
};

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		point s, e;
		scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);

		int n;
		scanf("%d", &n);

		int c = 0;

		for (int i = 1; i <= n; i++) {

			point k;
			scanf("%d %d %d", &k.x, &k.y, &k.r);

			k.r *= k.r;

			int d = s - k;

			int d2 = e - k;

			d -= k.r;
			d2 -= k.r;

			if ((long long)d*d2 < 0)c++; // in to out, out to in

		}

		printf("%d\n", c);

	}

}