#include <stdio.h>

#define ll long long

ll cnt(ll v){

	if(v == 0)return 0LL;

	ll ret = 0;

	for(ll i=1; i <= 60; i++){
		ret += v / (1LL<<i) * (1LL<<(i-1));

		ll rem = v % (1LL<<i) - ((1LL<<(i-1)) - 1);

		if(rem > 0)ret += rem;

	}

	return ret;

}

/*
	0000
	0001
	0010
	0011
	0100
	0101
	0110
	0111
	1000
*/

int main(){

	ll a, b;
	scanf("%lld %lld", &a, &b);

	printf("%lld\n", cnt(b) - cnt(a-1));

}
