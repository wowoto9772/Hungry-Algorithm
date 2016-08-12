#include <stdio.h>
#include <math.h>

int x[1003], y[1003], v[1003];

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	int n;
	scanf("%d", &n);

	double ans = 987653432111LL;

	for (int i = 1; i <= n; i++) {

		scanf("%d %d %d", &x[i], &y[i], &v[i]);

		int k = (a - x[i]) * (a - x[i]) + (b - y[i]) * (b - y[i]);

		double _k = sqrt((double)k) / v[i];

		if (ans > _k)ans = _k;

	}

	printf("%lf\n", ans);

}
