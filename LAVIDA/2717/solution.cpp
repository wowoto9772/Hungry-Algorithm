#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);

	double A = 0.0;
	for (int t = 1; t <= 5; t++){

		double M = 0.0;

		for (int i = 1; i <= n; i++){

			double x;
			scanf("%lf", &x);

			if (M < x)M = x;

		}

		A += M;
	}

	printf("%.3lf\n", A);

}