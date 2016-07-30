#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
	int n;
	while (scanf("%d", &n) == 1){

		ll stable[] = { 2, 5 };

		ll num[] = { 2, 5 };
		ll cnt[] = { 0, 0 };

		ll l = 1, r = 10000000000000000LL, m;
		while (l <= r){
			m = (l + r) / 2;

			num[0] = 2, num[1] = 5;
			cnt[0] = cnt[1] = 0;

			for (int i = 0; i < 2; i++){
				while (num[i] <= m){
					cnt[i] += m / num[i];
					if (cnt[i] >= n)break;
					num[i] *= stable[i];
				}
			}

			ll cmp = min(cnt[0], cnt[1]);
			if (cmp >= n){
				r = m - 1;
			}
			else
				l = m + 1;
		}

		num[0] = 2, num[1] = 5;
		cnt[0] = cnt[1] = 0;

		for (int i = 0; i < 2; i++){
			while (num[i] <= m){
				cnt[i] += m / num[i];
				num[i] *= stable[i];
			}
		}

		cnt[0] = min(cnt[0], cnt[1]);
		if (cnt[0] < n)m++;

		num[0] = 2, num[1] = 5;
		cnt[0] = cnt[1] = 0;

		for (int i = 0; i < 2; i++){
			while (num[i] <= m){
				cnt[i] += m / num[i];
				num[i] *= stable[i];
			}
		}

		cnt[0] = min(cnt[0], cnt[1]);

		if (cnt[0] != n)m = -1;

		printf("%lld\n", m);
	}
}