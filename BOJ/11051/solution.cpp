#include <stdio.h>
#define ll long long
#define mod 10007

bool p[1003];
int P[1003];
int c[1003] = { 0 };
int top;

ll modpowers(ll a, ll n){ // a^n
	ll ret = 1;
	while (n){
		if (n & 1)ret = (ret * a) % mod;
		n >>= 1LL;
		a = (a * a) % mod;
	}return ret;
}

void func(int val, int flg){
	for (int i = 0; i < top; i++){
		int k = P[i];
		while (k <= val){
			c[i] += flg * (val / k);
			k *= P[i];
		}
	}
}

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++){
		if (!p[i]){
			P[top++] = i;
			if (i*i > n)continue;
			for (int j = i*i; j <= n; j += i)p[j] = true;
		}
	}

	// N ! / K ! / N-K !
	func(n, 1);
	func(k, -1);
	func(n - k, -1);

	ll ans = 1;
	for (int i = 0; i < top; i++){
		ans *= modpowers(P[i], c[i]);
		ans %= mod;
	}

	printf("%lld\n", ans);
}