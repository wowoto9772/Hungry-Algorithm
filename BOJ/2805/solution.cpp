#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define ll long long

using namespace std;

int t[1000003];

int main(){
	int n, need;
	scanf("%d %d", &n, &need);

	for (int i = 0; i < n; i++){
		scanf("%d", &t[i]);
	}

	sort(t, t + n);

	ll l = 1, r = INT_MAX, cut;
	ll ans = 0;

	while (l <= r){
		cut = (l + r) / 2;

		ll rem = 0;
		for (int i = 0; i < n; i++){
			if (cut < t[i]){
				rem += t[i] - cut;
				if (rem > need)break;
			}
		}

		if (rem < need){
			r = cut - 1;
		}
		else{
			ans = max(ans, cut);
			l = cut + 1;
		}
	}

	printf("%lld\n", ans);
}