#include <stdio.h>
#include <math.h>

#define g 9.81
#define pi acos(-1.0)

double v_0;
double j, p, H, L;

double l, avl, alp;

double f(double l){
	return -g / 2.0*l*l / (v_0*v_0) + H + p;
}

double fp(double l){
	return -g*l / (v_0*v_0 - 0);
}

double set(double m1, double m2){
	double x1 = 1, y1 = m1, x2 = 1, y2 = m2;
	double seta = acos((1.0 + y1*y2) / (sqrt(1.0 + y1*y1) * sqrt(1.0 + y2*y2))); // radian
	return seta*180/pi; // degree
}

double absl(double a){ return a < -a ? -a : a; }

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%lf %lf %lf %lf", &j, &p, &H, &L);
		// v_0
		v_0 = sqrt(2*g*j);

		// 0 <= l < L/2

		double ll = 0, lr = L / 2.0, m;
		double hp;
		int c = 50;
		while (c--){
			m = (ll + lr) / 2.0;
			double hl = H*(1 - 2 * (m*m / (L*L)));
			double fl = f(m);
			if (hl < fl)ll = m;
			else if (hl > fl)lr = m;
		}

		l = m;
		avl = sqrt(2 * g * (j + p + H - f(l)));
		hp = -4 * H * l / (L*L);
		alp = set(hp, fp(l));

		double flag = absl(l - L / 2.0);
		if (flag < 1e-9){ // L/2 <= l < L

			ll = L / 2.0, lr = L;

			c = 50;
			while (c--){
				m = (ll + lr) / 2.0;
				double hl = 2 * H*(m / L - 1)*(m / L - 1);
				double fl = f(m);
				if (hl < fl)ll = m;
				else if (hl > fl)lr = m;
			}

			l = m;
			avl = sqrt(2 * g * (j + p + H - f(l)));
			hp = 4 * H * ((l - L) / (L*L));
			alp = set(hp, fp(l));

			flag = absl(l - L);
			if (flag < 1e-9){ // L <= l
				l = sqrt(2*(H+p)*v_0*v_0/g);
				avl = sqrt(2 * g * (j + p + H - f(l)));
				alp = set(0.0, fp(l));

				printf("%.8lf %.8lf %.8lf\n", l, avl, alp);
			}
			else{
				printf("%.8lf %.8lf %.8lf\n", l, avl, alp);
			}
		}
		else{
			printf("%.8lf %.8lf %.8lf\n", l, avl, alp);
		}
		// output : l, |vl|, speed-angle
	}
}