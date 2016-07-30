#include <stdio.h>
#include <map>

#define mod 1000000007

using namespace std;

#define ll long long

map <ll, ll> F;

ll fib(ll a) {
	if (a < 2)return 1;
	if (F[a])return F[a];
	return F[a] = (fib((a + 1) / 2)*fib(a / 2) + fib((a - 1) / 2)*fib((a - 2) / 2)) % mod;
}

ll gcd(ll a, ll b) {
	ll m = 1;
	while (m) {
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int main() {

	ll a, b;
	scanf("%lld %lld", &a, &b);

	ll g = gcd(a, b); 
	// gcd(F(a), F(b)) = F(gcd(a,b))

	printf("%lld\n", fib(g - 1));

}