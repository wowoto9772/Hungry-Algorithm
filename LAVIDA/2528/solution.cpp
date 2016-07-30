#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

struct point{
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y){}
};

typedef point Vector;

Vector operator +(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator -(Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator *(Vector A, double p)
{
	return Vector(A.x*p, A.y*p);
}
Vector operator /(Vector A, double p)
{
	return Vector(A.x / p, A.y / p);
}

point Meet(point &A, point &B, point &C, point &D){
	// line AB, line CD
	point ret;
	if (fabs(A.x - B.x) < 1e-9){
		ret.x = A.x;
		point delta = D - C;
		ret.y = delta.y / delta.x * (ret.x - C.x) + C.y;
	}
	else if (fabs(C.x - D.x) < 1e-9){
		ret.x = C.x;
		point delta = B - A;
		ret.y = delta.y / delta.x * (ret.x - A.x) + A.y;
	}
	else{
		point dAB = B - A, dCD = D - C;
		// occured over flow
		double mAB = dAB.y / dAB.x, mCD = dCD.y / dCD.x;

		/*
			dAB.y / dAB.x * (x - A.x) + A.y
			= dCD.y / dCD.x * (x - C.x) + C.y

			mAB * x - A.x * mAB + A.y
			= mCD * x - C.x * mCD + C.y
		*/

		ret.x = (A.x * mAB - A.y - C.x * mCD + C.y) / (mAB - mCD);
		if (ret.x == -0.0)ret.x = 0.0;
		ret.y = mAB*(ret.x - A.x) + A.y;
	}

	return ret;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		point A, B, C;
		scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);

		point dAC = C - A;
		point F = C;
		F.x -= dAC.y;
		F.y += dAC.x;
		point dCA = A - C;
		point G = F + dCA;
		point dCB = B - C;
		point J = B;
		J.x -= dCB.y;
		J.y += dCB.x;
		point H = J - dCB; // -dCB = dBC
		point dAB = B - A;
		point D = A;
		D.y -= dAB.x;
		D.x += dAB.y;
		point E = D + dAB;

		point L = (G + D) / 2;
		point M = (E + J) / 2;
		point N = (F + H) / 2;

		// seek line AL & line BM meeting points

		point ExoCntr = Meet(A, L, M, B);
		printf("%.4lf %.4lf\n", ExoCntr.x, ExoCntr.y);
	}
}

/*
14
0.0 0.0
5.0 0.0
0.0 -5.0
0.0 0.0
5.0 0.0
0.0 5.0
0.0 0.0
-5.0 0.0
0.0 5.0
0.0 0.0
-5.0 0.0
0.0 -5.0
-5.0 0.0
-5.0 -5.0
0.0 -5.0
5.0 0.0
5.0 -5.0
0.0 -5.0
5.0 0.0
5.0 5.0
0.0 5.0
0.0 5.0
-5.0 5.0
-5.0 0.0

*/

/*

#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

struct point{
double x, y;
point(double x = 0, double y = 0) :x(x), y(y){}
};

typedef point Vector;

Vector operator +(Vector A, Vector B)
{
return Vector(A.x + B.x, A.y + B.y);
}
Vector operator -(Vector A, Vector B)
{
return Vector(A.x - B.x, A.y - B.y);
}
Vector operator *(Vector A, double p)
{
return Vector(A.x*p, A.y*p);
}
Vector operator /(Vector A, double p)
{
return Vector(A.x / p, A.y / p);
}

double Dot(Vector A, Vector B){
// Inner Product (Scalar product or Dot Product)
return A.x*B.x + A.y*B.y;
}

double Length(Vector A){
// Vector A's Length
return sqrt(Dot(A, A));
}

Vector Unit(Vector A){
// Unit Vector (Normalization)
double L = Length(A);
return Vector(A.x / L, A.y / L);
}

Vector Normal(Vector A){
// Normal Unit Vector
Vector B(-A.y, A.x);
return Unit(B);
}

double Angle(Vector A){
// atan2 is more accuracy than atan
return atan2(A.y, A.x);
}

point GetCircleCenterTwo(point &a, point &b, double r){ // know two points
r *= 2.0; // diameter (radius * 2)
point mid = (a + b) / 2.0;
double d = sqrt(r*r / 4.0 - Length(mid - a)*Length(mid - a));
double rad = Angle(Normal(b - a));
return point(mid.x + d*cos(rad), mid.y + d*sin(rad));
}

point GetCircleCenterThree(point p1, point p2, point p3) { // know three points by kcm1700
double cx, cy;
{
double x1 = p1.x, x2 = p2.x, x3 = p3.x;
double y1 = p1.y, y2 = p2.y, y3 = p3.y;
double a = x1*(y2 - y3) + y1*(x3 - x2) + x2*y3 - y2*x3;
double f1 = x1*x1 + y1*y1;
double f2 = x2*x2 + y2*y2;
double f3 = x3*x3 + y3*y3;
double bx = +(y2*(f3 - f1) + y3*(f1 - f2) + y1*(f2 - f3));
double by = -(x2*(f3 - f1) + x3*(f1 - f2) + x1*(f2 - f3));
cx = -bx / (2 * a);
cy = -by / (2 * a);
}
return point(cx, cy);
}

*/