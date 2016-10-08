#include <cstdio>
#include <map>

using ll = long long;

using namespace std;

map <ll, ll> dp;

int p, q, x, y;

ll dy(ll n){

    if(n <= 0)return 1LL;
    
    if(dp.find(n) != dp.end())return dp[n];

    dp[n] = 0;

    return dp[n] = dy(n/p - x) + dy(n/q - y);

}

int main(){

    ll n;
    scanf("%lld %d %d %d %d", &n, &p, &q, &x, &y);

    printf("%lld\n", dy(n));

}
