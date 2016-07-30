#include <stdio.h>
#include <math.h>

int main()
{
	long long x, y, k;
	while (scanf("%lld %lld %lld", &x, &y, &k) == 3){
		if (x){
			double p = y * log10((double)x) + 1;
			int p_ = p;

			long long ret = x;

			for (int i = 1; i < y; i++){
				ret *= x;
				ret %= 100000;
			}

			int m = 1;

			for (int i = 0; i <= k; i++)m *= 10;

			if (p_ > k)printf("%lld\n", ((ret%m) / (m / 10)));
			else
				printf("-1\n");
		}
		else{
			if (k == 0)printf("0\n");
			else
				printf("-1\n");
		}
	}
}