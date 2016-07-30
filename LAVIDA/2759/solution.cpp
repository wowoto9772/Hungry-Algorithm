#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

#define mod 1000000007LL

ll tpw[100003] = { 1, };

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

pair <ll, ll> extgcd(ll a, ll b) {
	if (b == 0)return make_pair(1, 0);
	pair <ll, ll> t = extgcd(b, a%b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

ll modinv(ll a, ll m) {
	return (extgcd(a, m).first % m + m) % m;
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		tpw[i] = tpw[i - 1] << 1LL;
		tpw[i] %= mod;
	}

	ll up = n + 1;
	ll down = 0;

	ll v = 1;

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		up--;
		down++;
		v *= up;
		v %= mod;
		v *= modinv(down, mod);
		v %= mod;
		ans += v * tpw[i];
		ans %= mod;
	}

	printf("%lld\n", ans);

}

// nC0*2^0 + nC1*2 + nC2*2^2 + nC3*2^3 + ... + nCn*2^n = (1+2)^n = 3^n
// nC1*2 + nC2*2^2 + ... + nCn*2^n = 3^n - nC0*2^0 = 3^n - 1

#include <stdio.h>
#define ll long long
#define mod 1000000007

int main() {

	int n;
	scanf("%d", &n);

	ll ans = 1;

	for (int i = 1; i <= n; i++) {
		ans *= 3;
		ans %= mod;
	}

	ans--;

	if (ans < 0)ans += mod;

	printf("%lld\n", ans);

}