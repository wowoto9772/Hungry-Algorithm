#include <stdio.h>
#include <math.h>

double x[27], y[27], r[27];

int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){

		for (int i = 1; i <= n; i++)scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);

		double ans = 0.0, ans2 = 0.0;

		for (double x_ = x[1] - r[1]; x_ <= x[1] + r[1]; x_ += 0.01){
			for (double y_ = y[1] - r[1]; y_ <= y[1] + r[1]; y_ += 0.01){
				double k = (x_ - x[1]) * (x_ - x[1]) + (y_ - y[1]) * (y_ - y[1]);
				if (k <= r[1] * r[1]){
					ans += 1;
					for (int i = 2; i <= n; i++){
						double k2 = (x_ - x[i]) * (x_ - x[i]) + (y_ - y[i]) * (y_ - y[i]);
						if (k2 <= r[i] * r[i]){
							ans2 += 1;
							break;
						}
					}
				}
			}
		}

		printf("%.2lf\n", ans2/ans);
	}
}