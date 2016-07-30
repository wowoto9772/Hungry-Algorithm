#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		double sum = 0;

		int n;
		scanf("%d", &n);

		while (n--) {
			int x, y, a, b;
			scanf("%d %d %d %d", &x, &y, &a, &b);
			double s = atan2(y, x);

			double s2 = atan2(b, a);

			double tmp = abs(s - s2);

			if (tmp >= pi) {
				tmp = 2 * pi - abs(s - s2);
			}

			sum += tmp;
		}

		printf("%.5lf\n", sum / (2 * pi));

	}

}