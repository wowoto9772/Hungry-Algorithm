#include <stdio.h>
#include <algorithm>

using namespace std;

int ab(int a) { return a < -a ? -a : a; }

class ele {
public:
	int g, a, b, n;
	bool operator<(const ele &A)const {
		return ab(g) > ab(A.g);
	}
}I[1003];

int main()
{
	int n, a, b;
	while (scanf("%d %d %d", &n, &a, &b) == 3) {
		if (!n && !a && !b)break;

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &I[i].n, &I[i].a, &I[i].b);
			I[i].g = I[i].a - I[i].b;
		}

		sort(I, I + n);

		int cst = 0;

		for (int i = 0; i < n; i++) {
			if (I[i].g > 0) {
				if (b) {
					int ub = b < I[i].n ? b : I[i].n;
					cst += I[i].b * ub;
					b -= ub;
					I[i].n -= ub;
				}
				if (I[i].n) {
					int ua = a < I[i].n ? a : I[i].n;
					cst += I[i].a * ua;
					a -= ua;
					I[i].n -= ua;
				}
			}
			else {
				if (a) {
					int ua = a < I[i].n ? a : I[i].n;
					cst += I[i].a * ua;
					a -= ua;
					I[i].n -= ua;
				}
				if (I[i].n) {
					int ub = b < I[i].n ? b : I[i].n;
					cst += I[i].b * ub;
					b -= ub;
					I[i].n -= ub;
				}
			}
		}

		printf("%d\n", cst);
	}
}