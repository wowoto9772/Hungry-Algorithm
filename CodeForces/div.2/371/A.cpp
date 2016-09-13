#include <stdio.h>

#include <algorithm>

using namespace std;

#define ll long long

int main(){

	ll l1, r1, l2, r2, k;
	scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);

	ll le = max(l1, l2);
	ll ri = min(r1, r2);

	ll ans;

	if(le > ri){
		ans = 0;
	}else{
		ans = ri - le + 1;
		if(le <= k && k <= ri)ans--;
	}

	printf("%lld", ans);

}
