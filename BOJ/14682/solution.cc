#include <cstdio>

using namespace std;
using ll = long long;

int main(){
    
    ll n;
    int k;
    scanf("%lld %d", &n, &k);
    
    ll ans = 0;
    
    for(int i=0; i<=k; i++){
        ans += n;
        n *= 10;
    }
    
    printf("%lld\n", ans);

}