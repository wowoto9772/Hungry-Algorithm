#include <stdio.h>

#define ll long long
#define mod 1000000007LL

char str[8];

ll powers(ll a, ll n){
	ll ret = 1;
	while (n){
		if (n & 1)ret = ret * a % mod;
		n >>= 1LL;
		a = a * a % mod;
	}return ret;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		ll n;
		scanf("%lld %s", &n, str);

		// 0 ~ 39 * 2 
		// 40 ~ 59 
		ll forty = 0, sixty = 0;
		for (int i = 0; i < 60; i++){
			bool flag = false;
			for (int j = 0; j < 6; j++){
				if (str[j] == '2')continue;
				else if (str[j] == '1' && i % (j + 1)){
					flag = true;
				}
				else if (str[j] == '0' && !(i % (j + 1))){
					flag = true;
				}
			}
			if (!flag){
				if (i < 40)forty++;
				else{
					sixty++;
				}
			}
		}
		sixty += forty;

		if (n < 2){
			int ans = 0;
			for (int i = 0; i < 10; i++){
				bool flag = false;
				for (int j = 0; j < 6; j++){
					if (str[j] == '2')continue;
					else if (str[j] == '1' && i % (j + 1)){
						flag = true;
					}
					else if (str[j] == '0' && !(i % (j + 1))){
						flag = true;
					}
				}
				if (!flag)ans++;
			}
			printf("%d\n", ans);
		}
		else{
			// An = 10^n / sixty + 40 forty
			ll Q = powers(10, n);
			Q -= 40;
			if (Q < 0)Q += mod;
			ll ans = (Q * powers(60, mod - 2)) % mod;
			// 60^(p-2) = 60 ^ (-1)
			ans *= sixty;
			ans %= mod;
			ans += forty;
			printf("%lld\n", ans);
		}
	}
}
/*
Fermat's Little Theorem (
a % p(prime number) != 0, then a^(p-1) % p = 1
a^(-1) = a^(p-2) % p

An = Bn * sixty + forty
Bn = (10 * Bn-1 + 6)
*/