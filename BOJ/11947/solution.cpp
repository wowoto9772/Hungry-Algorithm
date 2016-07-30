#include <stdio.h>

#define ll long long

int main(){

	int t;
	scanf("%d", &t);

	while (t--){
		
		ll n;
		scanf("%lld", &n);

		ll org = n;

		ll ten = 1;
		while (n / 10){
			n /= 10LL;
			ten *= 10LL;
		}

		if (n >= 5)printf("%lld\n", 5 * ten * (5 * ten - 1)); // 5000 4999
		else{
			printf("%lld\n", org * (10LL * ten - 1 - org));
		}

	}

}