#include <cstdio>
#include <algorithm>
using namespace std;

#define le(i) (i<<1)
#define ri(i) ((i<<1)|1)

using ll = long long;

int k;
ll t[1<<22];

ll ans = 0;

ll son(int c){

    if(c > k)return 0LL;

    ll l = son(le(c));
    ll r = son(ri(c));

    ans += t[c] + abs(l-r);

    return max(l, r) + t[c];

}

int main(){

    int n;
    scanf("%d", &n);

    k = (1<<(n+1))-1;

    for(int i=2; i<=k; i++)scanf("%lld", &t[i]);

    son(1);

    printf("%lld\n", ans);

}
