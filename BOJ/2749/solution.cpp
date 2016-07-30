#include <stdio.h>
#include <map>

#define ll long long
#define mod 1000000

using namespace std;

map <ll, ll> F;

ll fibonacci(ll a)
{
	if (a < 2) return 1;
	if (F[a]) return F[a];
	return F[a] = (fibonacci((a + 1) / 2)*fibonacci(a / 2) + fibonacci((a - 1) / 2)*fibonacci((a - 2) / 2)) % mod;
}

int main()
{
	ll a;
	scanf("%lld", &a);

	printf("%lld\n", (a == 0 ? 0 : fibonacci(a - 1)));
}