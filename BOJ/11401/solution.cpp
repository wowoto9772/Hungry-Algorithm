#include <stdio.h>
#include <vector>

#define ll long long

#define mod 1000000007LL

using namespace std;

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
 * Dependencies: none */
pair<long long, long long> extended_gcd(long long a, long long b) {
	if (b == 0) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

/* Find x in [0,m) s.t. ax ≡ gcd(a, m) (mod m)
 * Dependencies: extended_gcd(a, b) */
long long modinverse(long long a, long long m) {
	return (extended_gcd(a, m).first % m + m) % m;
}

ll f[4000003] = {1,};

int main(){


	int n, k;
	scanf("%d %d", &n, &k);

	int l = n-k;

	// n! / (l!k!)

	for(ll i=1; i<=n; i++){
		f[i] = f[i-1] * i;
		f[i] %= mod;
	}

	printf("%lld\n", (((f[n] * modinverse(f[l], mod)) % mod) * modinverse(f[k], mod)) % mod);

}
