#include <stdio.h>

#include <algorithm>

using namespace std;

#define ll long long

int main(){

	ll k, a, b;
	scanf("%lld %lld %lld", &k, &a, &b);

	ll ans = 0;

	if(a <= 0 && 0 <= b)ans++;

	if(b < 0){
		ans += abs(a) / k - (abs(b) - 1) / k;
	}else if(a <= 0 && b >= 0){
		ans += (b / k) + abs(a) / k;
	}else if(a > 0){
		ans += b / k - (a-1) / k;
	}

	printf("%lld\n", ans);

}
