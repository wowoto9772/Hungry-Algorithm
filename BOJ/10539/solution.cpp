#include <cstdio>

using namespace std;
using ll = long long;

int main(){

    int n;
    scanf("%d", &n);

    ll s = 0;

    for(int i=1; i<=n; i++){
        int e;
        scanf("%d", &e);
        ll d = (ll)e*i - s;
        printf("%lld ", d);
        s += d;
    }

}
