#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		double a, b, c, d;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

		if (!a || !b || !c || !d)printf("NOT ATTENDED\n");
		else{
			double e = (a + b + c + d) / 4.0;
			double k = e - (int)e;
			int x = e;

			if (k < 0.25){
				printf("%d.0\n", x);
			}
			else if (k < 0.75){
				printf("%d.5\n", x);
			}
			else{
				printf("%.0lf.0\n", e);
			}
		}
	}
}