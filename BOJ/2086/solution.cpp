#include <stdio.h>
#include <map>

#define ll long long
#define mod 1000000000

using namespace std;

map <ll, ll> F;

ll fibonacci(ll a)
{
	if (a < 2) return 1;
	if (F[a]) return F[a];
	return F[a] = (fibonacci((a + 1) / 2)*fibonacci(a / 2) + fibonacci((a - 1) / 2)*fibonacci((a - 2) / 2)) % mod;
}

ll ans(ll n) {
	return (n == 0 ? n : fibonacci(n - 1));
}

int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);

	ll v = ((ans(b + 2) - 1 + mod) % mod - (ans(a - 1 + 2) - 1 + mod) % mod + mod) % mod;

	printf("%lld\n", v);

}