#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

ll e[200003];
ll c[400003];

int main(){

    int n;
    scanf("%d", &n);

    set <int> v;

    for(int i=1; i<=n; i++){
        scanf("%lld", &e[i]);
        v.insert(e[i]);
    }

    sort(e+1, e+1+n);

    for(int i=1; i<=n; i++){
        c[e[i]]++;
    }

    for(int i=1; i<=400000; i++)c[i] += c[i-1];

    ll ans = 0;

    for(auto &k : v){
        
        ll tmp = 0;
        ll s = 2*k;

        while(s - k <= e[n]){
            tmp += (c[s-1] - c[s-k-1]) * (s-k);
            s += k;
        }

        ans = max(ans, tmp);

    }

    printf("%lld\n", ans);

    return 0;

}
