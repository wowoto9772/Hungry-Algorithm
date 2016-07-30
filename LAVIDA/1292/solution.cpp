#include <stdio.h>

long long x[2], y[2], r[2];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		for (int i = 0; i < 2; i++)scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);

		long long d = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);

		long long RM = (r[0] + r[1]) * (r[0] + r[1]);
		
		long long Rm = (r[0] - r[1]) * (r[0] - r[1]);

		int ans = 0;

		if (d == 0 && r[0] == r[1])ans = -1; // coincidence
		else if (d == RM || d == Rm)ans = 1; // circumscribed, inscribed
		else if (d < RM && d > Rm)ans = 2;   // meet

		printf("%d\n", ans);
	}
}