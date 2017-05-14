#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

ll gcd(ll a, ll b){
    ll m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }return a;
}

/* find a pair (c,d) s.t. ac + bd = gcd(a,b)
 *  * Dependencies: none */
PLL extended_gcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    PLL t = extended_gcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}

/* Find x in [0,m) s.t. ax ≡ gcd(a, m) (mod m)
 *  * Dependencies: extended_gcd(a, b) */
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}

int main(){

    ll n, a;
    scanf("%lld %lld", &n, &a);

    printf("%lld ", n-a);

    if(gcd(n, a) != 1)printf("-1\n");
    else{
        printf("%lld\n", modinverse(a, n));
    }

}
