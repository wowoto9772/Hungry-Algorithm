#include <stdio.h>

int main()
{
	long long a, b;
	while (scanf("%lld %lld", &a, &b) == 2 && a && b){
		long long mod = 1;
		long long a_ = a, b_ = b;
		while (mod){
			mod = a_ % b_;
			a_ = b_;
			b_ = mod;
		}
		long long c = a * b / a_;
		printf("%lld\n", c/a * c/b);
	}
}