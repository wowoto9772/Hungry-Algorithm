#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;
using PLL = pair<ll, ll>;

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
 * Dependencies: none */
PLL extended_gcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    PLL t = extended_gcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}

/* Find x in [0,m) s.t. ax ≡ gcd(a, m) (mod m)
 * Dependencies: extended_gcd(a, b) */
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}

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

const ll lmod = 1000000007LL;

ll fac[4000003] = {1}, ifac[4000003];

int main(){

    for(int i=1; i<=4000000; i++){
        fac[i] = fac[i-1] * i;
        fac[i] %= lmod;
    }

    int t;
    scanf("%d", &t);

    while(t--){

        int n, k;
        scanf("%d %d", &n, &k);

        if(ifac[k] == 0)ifac[k] = modinverse(fac[k], lmod);
        if(ifac[n-k] == 0)ifac[n-k] = modinverse(fac[n-k], lmod);
        printf("%lld\n", (((fac[n] * ifac[k]) % lmod) * ifac[n-k]) % lmod);

    }

}
