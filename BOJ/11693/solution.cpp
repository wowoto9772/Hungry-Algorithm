#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long
#define mod 1000000007

ll invmod(int n, int k){
	if (n == 1)return k;
	ll div = mod / n + 1;
	return invmod((ll)(n*div) % mod, ((ll)k*div) % mod);
}
	
ll modpowers(ll a, ll n){ // a^n
	ll ret = 1;
	while (n){
		if (n & 1)ret = ret * a % mod;
		n >>= 1LL;
		a = a * a % mod;
	}return ret;
}

/*
Usage
Fermat's Little Theorem
a % p(prime number) != 0, then a^(p-1) % p = 1
a^(-1) = a^(p-2) % p
60^(p-2) = 60 ^ (-1)
10^n / 60 = modpowers(10, n) * modpowers(60, mod-2))
*/

ll sum(ll r, ll n){
	//return (modpowers(r, n) - 1) * (modpowers(r - 1, mod - 2)) % mod;
	return ((modpowers(r, n) - 1) * invmod(r - 1, 1)) % mod;
	// 등비수열 1 + a + ar + ... + ar^(n-1)
	// 합은 a(r^n-1)/(r - 1)
}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	if (!m)printf("1\n");
	else{

		vector <int> p;
		vector <ll> c;
		for (int i = 2; i*i <= n; i++){
			if (n%i)continue;
			int k = 0;
			while (!(n%i)){
				n /= i;
				k++;
			}
			p.push_back(i);
			c.push_back(k);
		}

		if (n != 1)p.push_back(n), c.push_back(1);

		for (int i = 0; i < p.size(); i++){
			c[i] *= m;
		}

		ll ans = 1;
		for (int i = 0; i < p.size(); i++){
			ans *= sum(p[i], c[i] + 1);
			ans %= mod;
		}

		printf("%lld\n", ans);

	}

}