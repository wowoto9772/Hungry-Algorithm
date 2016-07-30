#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {

		int v;
		scanf("%d", &v);

		printf("%d ", v);

		double d, a, b, p;

		scanf("%lf %lf %lf %lf", &d, &a, &b, &p);

		double k = d / (a + b); // time

		printf("%.2lf\n", p * k);

	}

}