#include <stdio.h>

// other's math solution
long long calcZero(long long n){
	if (n < 0)return 0; // first n : 0 ==> current n : -1
	long long ret = 1;
	long long n10 = 1, ntail = 0;
	while (n){
		if (n % 10)ret += n / 10 * n10;
		else
			ret += (n / 10 - 1)*n10 + (ntail + 1);
		ntail += n % 10 * n10;
		n /= 10;
		n10 *= 10LL;
	}return ret;
}

int main()
{
	long long a, b;
	while (scanf("%lld %lld", &a, &b) == 2 && a >= 0){
		printf("%lld\n", calcZero(b) - calcZero(a - 1));
	}
}