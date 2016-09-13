#include <stdio.h>

#include <math.h>

#include <vector>

#include <algorithm>

using namespace std;

double calc(double len, double r){

	return 1.0 - (2.0*r) / (len + r);

}

const double pi = acos(-1.0);

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		
		double a, b;
		int k;
		
		scanf("%lf %lf %d", &a, &b, &k);

		double c = sqrt(a*a+b*b);

		double r = a * b / (a+b+c);


		// h : b, w : a

		double aa = sqrt((a-r)*(a-r)+r*r);
		double bb = sqrt((b-r)*(b-r)+r*r);
		double cc = sqrt(2.0)*r;

		double ar, br, cr;

		ar = calc(aa, r);
		br = calc(bb, r);
		cr = calc(cc, r);

		vector < double > cir;

		cir.push_back(r);

		double x = r;

		for(int i=1; i<=100; i++){
			x *= ar;
			cir.push_back(x);
		}

		x = r;

		for(int i=1; i<=100; i++){
			x *= br;
			cir.push_back(x);
		}

		x = r;

		for(int i=1; i<=100; i++){
			x *= cr;
			cir.push_back(x);
		}

		sort(cir.begin(), cir.end());

		printf("%.8lf\n", cir[cir.size()-k] * cir[cir.size()-k] * pi);

	}

}
