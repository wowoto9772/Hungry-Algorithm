#include <stdio.h>

int main()
{
	double a, b, c, d, m, t;
	while (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &m, &t) == 6){
		double l = 0, r = 10000, v;
		int ac = 200;
		while (l <= r && ac--){
			v = (l + r) / 2.0;
			double s = m*(a*v*v*v*v + b*v*v*v + c*v*v + d*v);
			if (t*v <= s)r = v;
			else
				l = v;
		}

		int a = v * 100;
		double a_ = a / 100.0;
		printf("%.2lf\n", a_);
	}
}

/*
	v in kilometers per hour
	the amount of fuel consumed in liters per hour
*/