#include <stdio.h>
#include <math.h>

double AV(double a){ return a < -a ? -a : a; }
double small(double a, double b){ return a < b ? a : b; }
double big(double a, double b){ return a < b ? b : a; }

class point{
public:
	double x, y;
};

class dat{
public:
	double d; // distance value
	bool mip; // meet impossible
};

point s[6] = { { 0.0, 0.0 }, { 54.0, 0.0 }, { 108.0, 0.0 }, { 0.0, 54.0 }, { 54.0, 54.0 }, { 108.0, 54.0 } };

bool LineCirdist(point l1, point l2, point cm){
	bool ret = false;
	double mx = small(l1.x, l2.x), Mx = big(l1.x, l2.x), my = small(l1.y, l2.y), My = big(l1.y, l2.y);
	double d = 0.0;
	if (l1.x == l2.x){
		d = AV(cm.x - l1.x);
		if (d < 2.0){
			if (my <= cm.y && cm.y <= My){
				ret = true;
			}
		}
	}
	else{
		double dx = l1.x - l2.x;
		double dy = l1.y - l2.y;
		double a = dy;
		double b = -dx;
		double c = dx*l1.y - dy*l1.x;
		d = AV(a*cm.x + b*cm.y + c) / sqrt(a*a + b*b);
		if (d < 2.0)
		{
			double a2 = dx;
			double b2 = dy;
			double c2 = -(cm.x*dx + cm.y*dy);
			double m = dy / dx;

			point x2;
			if (m == 0){
				x2.x = cm.x;
				x2.y = l1.y;
			}
			else{
				x2.x = (cm.y - l1.y + cm.x / m + m*l1.x) / (m + 1 / m);
				x2.y = (x2.x - cm.x) / (-m) + cm.y;
			}
			if (0.0 <= x2.x && x2.x <= 108.0){
				if (0.0 <= x2.y && x2.y <= 54.0){
					if (mx <= x2.x && x2.x <= Mx){
						if (my <= x2.y && x2.y <= My){
							ret = true;
						}
					}
				}
			}
		}
	}

	return ret; // true : impossible
}

point OnePoint(point l1, point l2){
	point ret;
	if (l1.x == l2.x){
		ret.x = l1.x;
		if (l1.y < l2.y)ret.y = l1.y - 2.0;
		else{
			ret.y = l1.y + 2.0;
		}
	}
	else{
		double dx = l1.x - l2.x;
		double dy = l1.y - l2.y;
		double m = dy / dx;

		point P1, P2;

		double a = m*m + 1;
		double b = l1.x + m*m*l1.x;
		double c = l1.x*l1.x + m*m*l1.x*l1.x - 4.0;

		P1.x = (b + sqrt(b*b - a*c)) / a;
		if (l1.x < l2.x){
			if (P1.x < l1.x){
				P1.y = m*(P1.x - l1.x) + l1.y;
				ret = P1;
			}
			else{
				P2.x = (b - sqrt(b*b - a*c)) / a;
				P2.y = m*(P2.x - l1.x) + l1.y;
				ret = P2;
			}
		}
		else{
			if (l1.x < P1.x){
				P1.y = m*(P1.x - l1.x) + l1.y;
				ret = P1;
			}
			else{
				P2.x = (b - sqrt(b*b - a*c)) / a;
				P2.y = m*(P2.x - l1.x) + l1.y;
				ret = P2;
			}
		}
	}
	return ret;
}

double dist(point a, point b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		point S, T;
		scanf("%lf %lf %lf %lf", &S.x, &S.y, &T.x, &T.y);
		point o[17];

		int p;
		scanf("%d", &p);

		for (int i = 0; i < p; i++){
			scanf("%lf %lf", &o[i].x, &o[i].y);
		}

		int c = 0;
		for (int i = 0; i < 6; i++){ // shot
			dat now;
			bool imp = false;
			point x = OnePoint(T, s[i]);

			if (x.x < 0.0 || x.x > 108.0 || x.y < 0.0 || x.y > 54.0)continue;
			if (LineCirdist(S, x, T))continue;

			for (int j = 0; !imp && j < p; j++){
				if (LineCirdist(T, s[i], o[j])){
					imp = true;
				}
				if (!imp){
					if (LineCirdist(S, x, o[j]) || dist(o[j], x) < 4.0){
						imp = true;
					}
				}
			}

			if (imp)continue;

			c++;
			if (c > 1)printf(" ");
			printf("%d", i + 1);
		}

		if (!c)printf("no shot");
		printf("\n");
	}
}