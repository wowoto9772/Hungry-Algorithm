#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	double ans = 0, cur = -1.0;
	for (int i = 1; i <= n; i++){
		double a;
		scanf("%lf", &a);

		if (cur*a > a){
			cur *= a;
		}
		else{
			cur = a;
		}
		if (ans < cur)ans = cur;
	}

	printf("%.3lf\n", ans);
}