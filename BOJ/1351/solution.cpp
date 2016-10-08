#include <cstdio>
#include <map>

using ll = long long;

using namespace std;

map <ll, ll> dp;

int p, q;

ll dy(ll n){
    
    if(dp.find(n) != dp.end())return dp[n];

    dp[n] = 0;

    return dp[n] = dy(n/p) + dy(n/q);

}

int main(){

    ll n;
    scanf("%lld %d %d", &n, &p, &q);

    dp[0] = 1LL;

    printf("%lld\n", dy(n));

}
