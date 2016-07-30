#include <stdio.h>
#include <math.h>

int main(){
	int T = 0;
	double r, r1, r2, r3;
	while (scanf("%lf %lf %lf %lf", &r, &r1, &r2, &r3) == 4){
		if (r < 0 && r1 < 0 && r2 < 0 && r3 < 0)break;
		double seta = acos((r - r2) / (r + r2));
		double seta2 = acos((r - r3) / (r + r3));
		double seta3 = seta;
		double seta4 = acos((r - r1) / (r + r1));
		double seta5 = seta4;
		double seta6 = seta2;
		double AB = r*(tan(seta3) + tan(seta4));
		double BC = r*(tan(seta) + tan(seta2));
		double AC = r*(tan(seta5) + tan(seta6));
		printf("Case %d: %.2lf\n", ++T, (AB + BC + AC)*r / 2.0);
	}
}