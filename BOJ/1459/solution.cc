#include <iostream>
#include <stdio.h>

using namespace std;
using ll = long long;

ll min(ll a, ll b){
	if(a > b)return b;
	return a;
}

ll max(ll a, ll b){
	if(a > b)return a;
	return b;
}

int main(){
	
	ll x, y, w, s;
	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
	
	ll g = min(x, y);
	ll ans = min(g*2*w, g*s);
	ll rem = max(x, y) - min(x, y);
	ll fin = rem * w;
	ll fin2 = (rem/2) * 2 * s;
	if(rem & 1)fin2 += w;
	printf("%lld\n", ans+min(fin, fin2));
	
}