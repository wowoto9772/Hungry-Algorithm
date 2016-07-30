#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	
	int tc = 0;

	int l, p, v;
	while (scanf("%d %d %d", &l, &p, &v) == 3) {

		if (!(l | p | v))break;

		ll ans = (v / p) * l;
		ans += min(v % p, l);

		printf("Case %d: %lld\n", ++tc, ans);

	}

}