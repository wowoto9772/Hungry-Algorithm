#include <stdio.h>
#include <math.h>

int scr[] = { 100, 80, 60, 40, 20, 0, 0, 0 };

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n = 3;

		int a = 0, b = 0;

		double x, y;

		for (int i = 1; i <= n; i++) {

			scanf("%lf %lf", &x, &y);

			double d = x*x + y*y;

			for (int j = 3; j <= 15; j += 3) {
				if (d <= j*j) {
					a += scr[j / 3 - 1];
					break;
				}
			}

		}

		for (int i = 1; i <= n; i++) {

			scanf("%lf %lf", &x, &y);

			double d = x*x + y*y;

			for (int j = 3; j <= 15; j += 3) {
				if (d <= j*j) {
					b += scr[j / 3 - 1];
					break;
				}
			}

		}

		printf("SCORE: %d to %d, ", a, b);

		if (a > b)printf("PLAYER 1 WINS");
		else if (a < b)printf("PLAYER 2 WINS");
		else
			printf("TIE");

		printf(".\n");

	}

}