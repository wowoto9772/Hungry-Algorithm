#include <cstdio>
#include <map>

using namespace std;
using ll = long long;

int main() {

	int t;
	scanf("%d", &t);
	int tc = 0;

	while (t--) {

		ll n, k;
		scanf("%lld %lld", &n, &k);

		map <ll, ll> my;
		my[n] = 1;

		printf("Case #%d: ", ++tc);

		while(true){
			auto &v = *(--my.end());
			k -= v.second;

			ll g = v.first >> 1;
			if (k <= 0) {
				if (v.first & 1)printf("%lld %lld\n", g, g);
				else
					printf("%lld %lld\n", g, g - 1);
				break;
			}
			if (v.first & 1) {
				my[g] += 2LL * v.second;
			}
			else {
				my[g] += v.second;
				my[g - 1] += v.second;
			}

			my.erase(--my.end());
		}

	}

}