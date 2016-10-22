#include <cstdio>
#include <algorithm>

using ll = long long;
using namespace std;

int d[2][6] = {{11, 12, 13, 10, 9, 8}, {4, 5, 6, 3, 2, 1}};

int main(){

    ll n;
    char k;
    scanf("%lld%c", &n, &k);

    ll ans = ((n-1) / 4) * 16LL;

    n %= 2;
    k -= 'a';

    ans += d[n][k];

    printf("%lld\n", ans);

}
