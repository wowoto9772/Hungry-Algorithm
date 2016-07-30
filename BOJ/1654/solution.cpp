#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

ll a[10003];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);

	ll l = 1, r = 10000000000003LL, m;

	ll ans = 0;

	while (l <= r){
		m = (l + r) / 2;

		ll cmp = 0;
		for (int i = 1; i <= n; i++){
			cmp += a[i] / m;
			if (cmp >= k)break;
		}
		if (cmp >= k){
			l = m + 1;
			ans = max(ans, m);
		}
		else
			r = m - 1;
	}

	printf("%lld\n", ans);
}