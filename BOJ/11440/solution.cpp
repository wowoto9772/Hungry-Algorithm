#include <stdio.h>
#include <map>

#define ll long long
#define mod 1000000007

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
	ll a;
	scanf("%lld", &a);

	printf("%lld\n", (ans(a) * ans(a+1)) % mod);

}