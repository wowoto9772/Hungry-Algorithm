//#include <stdio.h>
//#include <math.h>
//#include <algorithm>
//
//using namespace std;
//
//class point{
//public:
//	double x, y;
//	bool operator<(const point &A)const{
//		if (x == A.x)return y < A.y;
//		return x < A.x;
//	}
//}D[35];
//
//class dpoint{
//public:
//	point a, b;
//};
//
//
//double Euclid_D(point &a, point &b){
//	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
//}
//
//dpoint Circle_Center(point &a, point &b, double r){
//	dpoint ret;
//
//	point  m{ (a.x + b.x) / 2, (a.y + b.y) / 2 };
//
//	// a m b
//	// a-center : r, m-center : h, a-M : l
//	// r*r = h*h + l*l
//
//	if (a.x == b.x){ // slope = infinity
//		ret.a.x = a.x - sqrt(r*r - (a.y - b.y)*(a.y - b.y) / 4.0);
//		ret.a.y = m.y;
//
//		ret.b.x = a.x + sqrt(r*r - (a.y - b.y)*(a.y - b.y) / 4.0);
//		ret.b.y = m.y;
//	}
//	else if (a.y == b.y){ // slope = 0
//		ret.a.x = m.x;
//		ret.a.y = a.y + sqrt(r*r - (a.x - b.x)*(a.x - b.x) / 4.0);
//
//		ret.b.x = m.x;
//		ret.b.y = a.y - sqrt(r*r - (a.x - b.x)*(a.x - b.x) / 4.0);
//	}
//	else{
//		double s = (b.y - a.y) / (b.x - a.x); // is slope
//
//		double H = r*r - Euclid_D(m, a);
//
//		// A : m.x / B : m.y
//		// y = (-1/s)(x-A) + B
//		// > b = (-1/s)(a-A) + B
//		// (a-A)^2 + (b-B)^2 = H
//		// > (a-A)^2 + ((-1/s)(a-A)+B-B)^2 = H
//		// > (a-A)^2 + ((-1/s)(a-A))^2 = H
//		// > (1 + (1/s)^2)(a-A)^2 = H
//
//		double w = 1 + (1 / (s*s));
//
//		// w(a-A)^2 = H = h^2
//		// > w(a^2-2Aa+A^2) - H = 0
//		// > wa^2 - 2wAa + wA^2 - H = 0
//		// a = (w +- sqrt(w^2A^2 - w^2A^2 + wH)) / w
//		// a = (w +- sqrt(wH)) / w
//		// > a = (1 +- h/(sqrt(w))
//		// b = (-1/s)(a-A) + B
//
//		double h = sqrt(H);
//
//		ret.a.x = (1 + h / sqrt(w));
//		ret.a.y = (-1 / s)*(ret.a.x - m.x) + m.y;
//
//		ret.b.x = (1 - h / sqrt(w));
//		ret.b.y = (-1 / s)*(ret.b.x - m.x) + m.y;
//	}
//	return ret;
//}
//
//int main(){
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n;
//		double r; // diameter radius * 2)
//		scanf("%d %lf", &n, &r);
//
//		r /= 2.0;
//
//		for (int i = 1; i <= n; i++)scanf("%lf %lf", &D[i].x, &D[i].y);
//
//		sort(D + 1, D + 1 + n);
//
//		int max = 1;
//
//		for (int i = 1; i <= n; i++){ // O(n^3)
//			for (int j = 1; j <= n; j++){
//				if (i == j)continue;
//
//				// Euclid_D(a, b) <= 2*r
//				if (sqrt(Euclid_D(D[i], D[j])) > r + 1e-5)continue;
//
//				dpoint cent = Circle_Center(D[i], D[j], r);
//
//				int c = 0;
//				for (int k = 1; k <= n; k++){
//					if (sqrt(Euclid_D(cent.a, D[k])) <= r + 1e-5){
//						c++;
//					}
//				}
//
//				int d = 0;
//				for (int k = 1; k <= n; k++){
//					if (sqrt(Euclid_D(cent.b, D[k])) <= r + 1e-5){
//						d++;
//					}
//				}
//
//				if (c < d){
//					if (max < d)max = d;
//				}
//				else{
//					if (max < c)max = c;
//				}
//			}
//		}
//
//		printf("%d\n", max);
//	}
//}



#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

class point{
public:
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y){}
}D[35];

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

point GetCircleCenter(point &a, point &b, double r){
	r *= 2.0; // diameter (radius * 2)
	point mid = (a + b) / 2.0;
	double d = sqrt(r*r / 4.0 - Length(mid - a)*Length(mid - a));
	double rad = Angle(Normal(b - a));
	return point(mid.x + d*cos(rad), mid.y + d*sin(rad));
}

int main(){

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		double r; // diameter (radius * 2)
		scanf("%d %lf", &n, &r);

		r /= 2.0;

		for (int i = 0; i < n; i++)scanf("%lf %lf", &D[i].x, &D[i].y);

		int max = 1; // any circle include at least one point

		for (int i = 0; i < n; i++){ // O(n^3)
			for (int j = 0; j < n; j++){
				if (i == j)continue;

				// EuclidDistance(a, b) <= 2*r
				if (Length(D[i] - D[j]) > 2 * r)continue;

				point mid = GetCircleCenter(D[i], D[j], r);

				int c = 0;
				for (int k = 0; k < n; k++){
					if (Length(mid - D[k]) <= r + 1e-5)
					{
						c++;
					}
				}

				if (max < c)max = c;
			}
		}

		printf("%d\n", max);
	}
}
