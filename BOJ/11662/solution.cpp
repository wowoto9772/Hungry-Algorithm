#include <stdio.h>
#include <math.h>

#define ll long long

int main(){
	ll Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

	ll b = Bx - Ax - Dx + Cx;
	ll d = By - Ay - Dy + Cy;

	ll a = Ax - Cx;
	ll c = Ay - Cy;

	// range(t) : 0 <= t <= 1
	double t = (a*b + c*d) / (double)(b*b + d*d);

	double dist;
	if (t > 1e-9 || b == 0 && d == 0){ 
		// minimum value ==> t : 0
		// b = d = 0 ==> same position, same vector
		dist = (Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy);
	}
	else{ 
		if (-1 >= t){ // minimum value ==> t : 1
			dist = (Bx - Dx)*(Bx - Dx) + (By - Dy)*(By - Dy);
		}
		else{
			dist = a*a + c*c - (a*b + c*d)*(a*b + c*d) / (double)(b*b + d*d);
		}
	}

	printf("%.10lf\n", sqrt(dist));
}