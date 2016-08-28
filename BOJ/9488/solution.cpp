#include <stdio.h>

#define ll long long

ll s[1000003];

int main(){

	for(ll i=1; i<=1000000; i++){
		s[i] = s[i-1] + i*(i+1)/2;
	}

	int n;
	while(scanf("%d", &n) == 1 && n){
		printf("%lld\n", s[n]);
	}

}
