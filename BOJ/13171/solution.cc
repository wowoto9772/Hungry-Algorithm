#include <cstdio>

using namespace std;
using ll = long long;
const ll lmod = 1000000007LL;

/* Find a^p mod m */
ll modpower(ll a, ll p, ll m){
    ll r = 1;
    while(p){
        if(p&1)r = (r*a) % m;
        a = (a*a) % m;
        p >>= 1;
    }
    return r;
}

int main(){
	ll n, a;
	scanf("%lld %lld", &n, &a);
	n %= lmod;
	printf("%lld\n", modpower(n, a, lmod));
}