#include <cstdio>

using namespace std;
using ll = long long;

const ll lmod = 1000000007LL;

ll power(ll a, ll p){
    if(p == -1)return 0LL;
    ll r = 1;
    while(p){
        if(p&1){
            r *= a;
            r %= lmod;
        }
        a *= a;
        a %= lmod;
        p >>= 1;
    }return r;
}

int main(){
    
    int t;
    scanf("%d", &t);
    
    ll ans = 0;
    
    while(t--){
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll x = power(2, b-1);
        ll y = (a*b) % lmod;
        ans += x*y;
        ans %= lmod;
    }
    
    printf("%lld\n", ans);

}
