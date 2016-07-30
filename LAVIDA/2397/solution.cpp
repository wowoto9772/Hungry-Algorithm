#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		long long a_ = pow(a, (double)b), b_ = pow(c, (double)d);
		if (a_ == b_)printf("SAME\n");
		else{
			if (a_ > b_)printf("%lld^%lld\n", a, b);
			else{
				printf("%lld^%lld\n", c, d);
			}
		}
	}
}