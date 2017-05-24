#include <cstdio>

using namespace std;

double min(double a, double b){
	if(a > b)return b;
	return a;
}

int gcd(int a, int b){
	int m = 1;
	while(m){
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}

int main(){
	
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	
	int p, q, r;
	scanf("%d %d %d", &p, &q, &r);
	
	int g = gcd(p, gcd(q, r));
	p /= g, q /= g, r /= g;
	
	double x = min(a/(double)p, min(b/(double)q, c/(double)r));
	a -= x*p;
	b -= x*q;
	c -= x*r;
	
	printf("%.5lf %.5lf %.5lf\n", a, b, c);
	
}