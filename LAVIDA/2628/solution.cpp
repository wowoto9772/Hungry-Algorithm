#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll zcnt(ll l, ll r, ll z){
	if (l > r)return 0;
	ll four = r / 4 - (l - 1) / 4;
	ll even = (r / 2 - (l - 1) / 2) - four;
	ll odd = (r - l + 1) - four - even;
	return four*z + (even + odd)*(z + 1);
}

int main()
{
	ll k;
	while (scanf("%lld", &k) == 1 && k){

		ll acnt = 0;
		for (int i = 1; i <= 18; i++){
			ll l = 1, r = 9, m;
			for (int j = 1; j < i; j++){
				l *= 10LL;
				r = r * 10LL + 9;
			}

			ll constl = l;
			ll constr = r;

			ll cnt = zcnt(l, r, i);
			acnt += cnt;
			if (acnt >= k){
				acnt -= cnt;

				while (l <= r){
					m = (l + r) / 2;
					ll flg = acnt + zcnt(constl, m, i);
					if (flg < k)l = m + 1;
					else{
						r = m - 1;
					}
				}

				for (ll cur = m - 2; cur <= m + 2; cur++){
					if (constl <= cur + 1){
						ll pls = 0;
						if (cur + 1 > constr)break;
						if (cur >= constl)pls += zcnt(constl, cur, i);
						acnt += pls;

						int str[30] = { 0 };
						int top = 0;

						ll x = cur + 1;
						ll cpyx = x;

						while (x){
							str[top++] = x % 10;
							x /= 10;
						}

						reverse(str, str + top);

						x = cpyx;

						if (x % 4 == 0){
							// ignore
						}
						else if (x % 2){ // add 2
							str[top++] = 2;
						}
						else{ // add 0
							str[top++] = 0;
						}

						bool flag = false;
						for (int j = 0; j < top; j++){
							if (acnt + (j + 1) == k){
								printf("%d\n", str[j]);
								flag = true;
								break;
							}
						}

						if (!flag){
							acnt -= pls;
						}
						else{
							break;
						}
					}
				}
				break;
			}
		}
	}
}