#include <stdio.h>
#define ll long long

int main(){

	int k;
	scanf("%d", &k);

	ll a = 1, b = 0;
	ll a_, b_;

	for (int i = 1; i <= k; i++){
		b_ = a + b;
		a_ = b;
		a = a_;
		b = b_;
	}

	printf("%lld %lld\n", a, b);

}