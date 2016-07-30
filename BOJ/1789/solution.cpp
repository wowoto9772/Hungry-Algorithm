#include <stdio.h>

#define ll long long

int main(){

	ll a;
	scanf("%lld", &a);

	ll c = 0;
	int m = 0;

	for (ll i = 1;; i++){
		if (c + i <= a){
			c += i; m++;
		}
		else
			break;
	}

	printf("%d\n", m);

}