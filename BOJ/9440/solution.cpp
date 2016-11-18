#include <cstdio>
#include <limits.h>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

ll calc(vector <int> e){
    sort(e.begin(), e.end());
    ll ret = -1;
    for(int i=0; i<e.size(); i++){
        if(e[i]){
           ret = e[i];
           for(int j=0; j<i; j++)ret *= 10LL;
           for(int j=i+1; j<e.size(); j++){
               ret = ret * 10LL + e[j];
           }
           return ret;
        }
    }
    return ret;
}

int main(){

    int n;
    while(scanf("%d", &n) == 1 && n){
        vector <int> v(n);
        for(int i=0; i<n; i++){
            scanf("%d", &v[i]);
        }
        ll ans = LLONG_MAX;
        for(int i=1; i<(1<<n); i++){
            vector <int> a, b;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    a.push_back(v[j]);
                }else{
                    b.push_back(v[j]);
                }
            }
            ll A = calc(a), B = calc(b);
            if(A == -1 || B == -1)continue;
            ans = min(ans, A + B);
        }
        printf("%lld\n", ans);
    }

}
