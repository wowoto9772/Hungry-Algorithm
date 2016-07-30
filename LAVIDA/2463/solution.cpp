#include <stdio.h>
#define ll long long

ll r(ll a){
	ll b = 0;
	while (a){
		b = b * 10 + a % 10;
		a /= 10;
	}return b;
}

int main(){
	int t;
	scanf("%d", &t);
	
	while (t--){
		ll a, b;
		scanf("%lld %lld", &a, &b);

		printf("%lld\n", r(r(a) + r(b)));
	}
}