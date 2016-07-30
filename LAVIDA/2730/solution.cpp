#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define ll long long

ll t[100003];

int main(){

	int n, p;
	scanf("%d %d", &n, &p);

	for (int i = 0; i < n; i++)scanf("%lld", &t[i]);

	ll l = 1, r = LLONG_MAX / 2, m;

	ll ans = LLONG_MAX / 2;

	while (l <= r){

		m = (l + r) / 2;

		ll cmp = 0;

		for (int i = 0; i < n && cmp <= p; i++){
			cmp += m / t[i];
		}

		if (cmp >= p){
			r = m - 1;
			ans = min(ans, m);
		}
		else{
			l = m + 1;
		}

	}

	printf("%lld\n", ans);

}