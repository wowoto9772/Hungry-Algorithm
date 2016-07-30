#include <stdio.h>
#include <math.h>

const double g = 9.80;
const double pi = acos(-1.0);

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		double xo, yo, xu, yu, w, d;
		scanf("%lf %lf %lf %lf %lf %lf", &xu, &yu, &xo, &yo, &w, &d);

		d = d * pi / 180.0; //degree to radian

		double dx = xo - xu;
		double dy = yo - yu;

		// v0cos(d)t + wt^2 / 2 = dx
		// v0sin(d)t - gt^2 / 2 = dy
		// (2dx-wt^2)tan(d) = 2dy + gt^2
		// t^2(g+wtan(d)) = 2dxtan(d) - 2dy

		double t = (2 * dx*tan(d) - 2 * dy) / (g + w*tan(d));
		t = sqrt(t);
		double v0 = (dy + g*t*t / 2.0) / (t*sin(d));

		if (0.0 <= v0 && v0 <= 300.0)printf("%.5lf\n", v0);
		else{
			printf("impossible\n");
		}

		// vector(x, y) = (cos(d), sin(d)) = (1/(1+tan(d)*tan(d)), tan(d)/(1+tan(d)*tan(d)))
	}
}