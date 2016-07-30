#include <stdio.h>
#include <math.h>

int main(){
	int t = 0;
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) == 3){
		if (!a && !b && !c)break;
		printf("Triangle #%d\n", ++t);

		if (c == -1){
			double q = sqrt((double)a*a + b*b);
			printf("c = %.3lf\n", q);
		}
		else if (a == -1){
			if (c*c - b*b > 0){
				double q = sqrt((double)c*c - b*b);
				printf("a = %.3lf\n", q);
			}
			else{
				printf("Impossible.\n");
			}
		}
		else{
			if (c*c - a*a > 0){
				double q = sqrt((double)c*c - a*a);
				printf("b = %.3lf\n", q);
			}
			else{
				printf("Impossible.\n");
			}
		}
		printf("\n");
	}
}