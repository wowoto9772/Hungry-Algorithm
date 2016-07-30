#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	int t;
	scanf("%d", &t);

	while (t--){

		ll n, k;
		scanf("%lld %lld", &n, &k);

		ll ck = k;
		vector <ll> p;
		vector <int> c;

		for (ll i = 2; i*i <= ck; i++){
			if (ck%i)continue;

			p.push_back(i);
			int d = 0;
			while (!(ck%i)){
				ck /= i;
				d++;
			}
			c.push_back(d);
		}
		if (ck != 1){
			p.push_back(ck);
			c.push_back(1);
		}

		ll ans = 0;
		ans = LLONG_MAX;
		for (int i = 0; i < p.size(); i++){
			int r = c[i];
			ll d = 0;
			ll cur = p[i];
			while (cur <= n){
				d += n / cur;
				if (cur > n / p[i]){ // prevent overflow
					break;
				}
				cur *= p[i];
			}

			ans = min(ans, d / r);
		}
		if (ans == LLONG_MAX)ans = 0;

		printf("%lld\n", ans);
	}
}