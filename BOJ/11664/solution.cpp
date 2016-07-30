#include <stdio.h>
#include <math.h>

int main(){

	int x[3], y[3], z[3];

	for (int i = 0; i < 3; i++)scanf("%d %d %d", &x[i], &y[i], &z[i]);

	int a1 = x[0] - x[2], b1 = y[0] - y[2], c1 = z[0] - z[2];
	int a2 = x[1] - x[0], b2 = y[1] - y[0], c2 = z[1] - z[0];

	int A = a2*a2 + b2*b2 + c2*c2;
	int B = a1*a2 + b1*b2 + c1*c2;
	int C = a1*a1 + b1*b1 + c1*c1;

	printf("%d %d %d\n", A, B, C);

	printf("%.8lf\n", sqrt((double)C - B*B / A));
}