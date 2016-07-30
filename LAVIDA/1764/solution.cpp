#include <stdio.h>
#include <math.h>

int c[11];
int n;
double ans(double x){
	double ret = 0;
	for (int i = n; i >= 0; i--){
		ret += c[i] * pow(x, i);
	}
	return ret < -ret ? -ret : ret;
}

int main(){
	scanf("%d", &n);

	for (int i = n; i >= 0; i--){
		scanf("%d", &c[i]);
	}

	double l, r;
	scanf("%lf %lf", &l, &r);

	int m;
	scanf("%d", &m);

	double x = (r - l);
	x /= m;

	double s = l;
	double e = r;

	s += x / 2.0; // 가운데 리만 합

	double A = 0;

	for (int i = 1; i <= m; i++){
		A += x * ans(s);
		s += x;
	}

	printf("%.2lf\n", A);
}