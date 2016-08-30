#include <cstdio>
#include <cmath>

#include <algorithm>

using namespace std;

int main(){

	int n;
	double d;

	scanf("%d %lf", &n, &d);

	double vx[2], vy[2], vz[2];

	for(int i=0; i<2; i++)scanf("%lf %lf %lf", &vx[i], &vy[i], &vz[i]);

	// vy0 vz0 vx0 vy0
	// vy1 vz1 vx1 vy1

	double a = vy[0] * vz[1] - vz[0] * vy[1];
	double b = vz[0] * vx[1] - vx[0] * vz[1];
	double c = vx[0] * vy[1] - vy[0] * vx[1];

	//printf("%lf %lf %lf\n", a, b, c);

	// (0, 0, 0) : ax + by + cz = 0

	int ans = 0;

	for(int i=1; i<=n; i++){

		for(int j=0; j<2; j++)scanf("%lf %lf %lf", &vx[j], &vy[j], &vz[j]);

		double x = vx[0] - vx[1] * d;
		double y = vy[0] - vy[1] * d;
		double z = vz[0] - vz[1] * d;

		//printf("%lf %lf %lf = %lf\n", x, y, z, a*x+b*y+c*z);

		if(fabs(a*x+b*y+c*z) < 1e-1){

			if(fabs(sqrt(x*x+y*y+z*z) - d) < 1e-1){
				ans++;
			}
		}

	}

	printf("%d\n", ans);

}
