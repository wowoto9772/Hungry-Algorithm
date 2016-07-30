#include <stdio.h>
#include <vector>
#define ll long long
const ll mod = 1LL << 32;

bool p[100000003];
int P[6000003];

ll modpowers(ll a, ll n){ // a^n
	ll ret = 1;
	while (n){
		if (n & 1)ret = (ret * a) % mod;
		n >>= 1LL;
		a = (a * a) % mod;
	}return ret;
}

int main(){
	int n;
	scanf("%d", &n);

	int top = 0;

	for (ll i = 2; i <= n; i++){
		if (!p[i]){
			P[top++] = i;
			if (i*i > n)continue;
			for (int j = i*i; j <= n; j += i){
				p[j] = true;
			}
		}
	}

	ll ans = 1;
	for (int i = 0; i < top; i++){
		int k = 0;
		ll a = P[i], c = P[i];
		if (c > n)break;
		while (c <= n){
			c *= a;
			k++;
		}
		ans *= (modpowers(a, k) % mod);
		ans %= mod;
	}

	printf("%lld\n", ans);
}