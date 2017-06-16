#include <cstdio>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const ll mkey[2] = {1000000000061LL, 1000000000039};

int main(){

    int n;
    scanf("%d", &n);
    
    set < pair <ll,ll> > my;
    
    for(int i=1; i<=n; i++){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        ll x[2] = {a, a};
        my.emplace(a, a);
        
        for(int j=1; j<=c; j++){
            for(int k=0; k<2; k++){
                x[k] *= b;
                x[k] %= mkey[k];
            }
            my.emplace(x[0], x[1]);
        }
    }
    
    printf("%d\n", my.size());

}
