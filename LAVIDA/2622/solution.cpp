#include <stdio.h>
#include <math.h>

const double pi = acos(-1.0);

double A(double a){ return a < -a ? -a : a; }

bool meet(double ax, double by, double c){
	// x^2 + (y-52.5)^2 = 6.0^2
	double ret = A(by*52.5 + c) / sqrt(ax*ax + by*by);
	return ret - (6.0 + 10.0) <= 1e-9;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		double T, x;
		scanf("%lf %lf", &T, &x);
		T *= 100.0; // meters to cm
		double X = x * pi / 180.0;

		double m = tan(X);
		double dt = 42.5 / m;

		if (T >= dt)T -= dt;

		dt *= 2.0;

		long long cycle = T / dt;
		int dir = cycle % 2;
		if (T / dt - cycle <= 1e-9){
			// ignore
		}
		else{
			dir++;
		}
		dir %= 2;

		T -= dt * cycle;
		double dy = 10.0;

		if (dir == 1){ // up
			m *= -1.0;
		}
		else{
			dy = 95.0;
		}

		double rh = -m*T + dy;

		// x^2 + (y-52.5)^2 = 6^2

		if (meet(m, -1.0, rh)){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}

	}
}