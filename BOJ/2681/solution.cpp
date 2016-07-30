#include <stdio.h> 
#include <math.h>
#include <algorithm>

using namespace std;

class point {
public:
	double x, y;
}S[4];

point InterSectionPoint(point I1, point I2, point J1, point J2) {
	point ret = { -1, -1 };
	if ((I1.x != I2.x) && (J1.x != J2.x)) {
		double M1 = (I2.y - I1.y) / (I2.x - I1.x);
		double M2 = (J2.y - J1.y) / (J2.x - J1.x);
		if (M1 != M2) {
			ret.x = (-M2 * J1.x + J1.y + M1 * I1.x - I1.y) / (M1 - M2);
			ret.y = M2 * (ret.x - J1.x) + J1.y;
		}
		else if (I1.x == I2.x) {
			ret.x = I1.x;
			ret.y = M2 * (ret.x - J1.x) + J1.y;
		}
		else if (J1.x == J2.x) {
			ret.x = J1.x;
			ret.y = M1 * (ret.x - J1.x) + J1.y;
		}
	}
	return ret;
}
double TriArea(point a, point b, point c) {
	return 0.5 * abs((a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y));
}
double QuadArea(point a, point b, point c, point d) {
	return 0.5 * abs((a.x*b.y + b.x*c.y + c.x*d.y + d.x*a.y) - (b.x*a.y + c.x*b.y + d.x*c.y + a.x*d.y));
}
double L(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		point A = { 0, 0 };
		point B, C, D, A_, B_, C_, D_;
		B.y = 0;

		scanf("%lf %lf %lf %lf %lf", &B.x, &C.x, &C.y, &D.x, &D.y);

		A_.x = (B.x + C.x) / 2;
		A_.y = (B.y + C.y) / 2;
		B_.x = (C.x + D.x) / 2;
		B_.y = (C.y + D.y) / 2;
		C_.x = (A.x + D.x) / 2;
		C_.y = (A.y + D.y) / 2;
		D_.x = (A.x + B.x) / 2;
		D_.y = (A.y + B.y) / 2;

		point CC_nDD_ = InterSectionPoint(C, C_, D, D_);
		point CC_nBB_ = InterSectionPoint(C, C_, B, B_);
		point AA_nDD_ = InterSectionPoint(A, A_, D, D_);
		point AA_nBB_ = InterSectionPoint(A, A_, B, B_);

		double len = L(AA_nBB_, CC_nBB_) + L(AA_nDD_, AA_nBB_) + L(AA_nDD_, CC_nDD_) + L(CC_nDD_, CC_nBB_);

		int alen = len;
		if (len - int(len) >= 1e-9)alen++;

		printf("%.3lf %.3lf %.3lf %.3lf %.3lf %d\n", TriArea(A, B, AA_nBB_), TriArea(B, C, CC_nBB_), TriArea(C, D, CC_nDD_), TriArea(A, D, AA_nDD_), QuadArea(AA_nDD_, CC_nDD_, CC_nBB_, AA_nBB_), alen);
	}
}