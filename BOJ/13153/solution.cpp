#include <stdio.h>
#include <math.h>

#define ll long long

class point{
	public:
		ll x, y;
}p[3];

ll dsqr(point &a, point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){

	for(int i=0; i<3; i++){
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}

	
	ll a_2 = dsqr(p[0], p[1]), b_2 = dsqr(p[1], p[2]), c_2 = dsqr(p[2], p[0]);
	double a = sqrt((double)a_2), b = sqrt((double)b_2), c = sqrt((double)c_2);

	double A = sqrt(double(4.0*a_2*b_2-(a_2+b_2-c_2)*(a_2+b_2-c_2))) / 4.0;

	double incr;
	scanf("%lf", &incr);

	double r = 2.0 * A / ((double)a+b+c);

	printf("%.5lf\n", (r-incr)/incr*100.0);

}
