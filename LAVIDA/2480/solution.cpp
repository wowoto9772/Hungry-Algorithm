#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {

	if (!a)return b;
	else if (!b)return a;

	int m = 1;

	while (m) {
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}

int main()
{
	int x1, x2, x3, y1, y2, y3;

	while (scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
		if (!x1 && !x2 && !x3 && !y1 && !y2 && !y3)return 0;

		double A = (double)(((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)) / 2.0);
		A = abs(A);

		int b = gcd(abs(x2 - x1), abs(y2 - y1)) + gcd(abs(x3 - x1), abs(y3 - y1)) + gcd(abs(x3 - x2), abs(y3 - y2));

		int I = (double)(A - b / 2.0 + 1); // Pick's theorem

		printf("%d\n", I);
	}
}
