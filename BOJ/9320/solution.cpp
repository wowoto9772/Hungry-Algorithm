#include <stdio.h>
#include <math.h>

#include <algorithm>

using namespace std;

double calc(double a, double b, int op)
{
	switch (op)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
	return -1;
}

void Solve()
{

	double x[4];
	for (int i = 0; i < 4; i++)scanf("%lf", &x[i]);
	sort(x, x + 4);

	bool ok = false;

	while (true) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++)
				{
					// (a*b) * (c*d)
					double a = calc(calc(x[0], x[1], i), calc(x[2], x[3], k), j);
					// ((a*b) * c) * d
					double b = calc(calc(calc(x[0], x[1], i), x[2], j), x[3], k);
					// (a * (b*c)) * d
					double c = calc(calc(x[0], calc(x[1], x[2], j), i), x[3], k);
					// a * ((b*c) * d)
					double d = calc(x[0], calc(calc(x[1], x[2], j), x[3], k), i);
					// a * (b * (c*d))
					double e = calc(x[0], calc(x[1], calc(x[2], x[3], k), j), i);

					ok |= (fabs(a - 24) <= 1e-9);
					ok |= (fabs(b - 24) <= 1e-9);
					ok |= (fabs(c - 24) <= 1e-9);
					ok |= (fabs(d - 24) <= 1e-9);
					ok |= (fabs(e - 24) <= 1e-9);
				}
			}
		}

		if (ok || !next_permutation(x, x + 4))break;

	} 
	
	printf("%s\n", ok ? "YES" : "NO");

}

int main()
{

	int n;
	scanf("%d", &n);

	while (n--) {
		Solve();
	}

}