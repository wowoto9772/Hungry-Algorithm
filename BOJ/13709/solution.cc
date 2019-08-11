#include <cstdio>
#include <set>

using namespace std;
using ll = long long;

set<ll> sets[64];

int getMostSignificantBit(ll v){
    for(int i=63; i>=0; i--)if(v&(1<<i))return i;
    return -1;
}

ll maxValue(ll a, ll b){
    if(a < b)a = b;
    return a;
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        ll v;
        scanf("%lld", &v);
        int idx = getMostSignificantBit(v);
        if(idx == -1)continue;
        sets[idx].insert(v);
    }

    ll ans = 0;
    for(int i=63; i>=0; i--){
        if(sets[i].size()){
            set<ll>::iterator it = sets[i].begin();
            ll cur = *it;
            set<ll> nextSet;
            for(set<ll>::iterator pt=(++it); pt!=sets[i].end(); pt++){
                ll nxt = (*pt) ^ cur;
                int idx = getMostSignificantBit(nxt);
                if (idx == -1)continue;
                nextSet.insert(nxt);
            }
            for (auto &i : nextSet){
                int idx = getMostSignificantBit(i);
                sets[idx].insert(i);
            }
            ans = maxValue(ans, ans^cur);
            printf("%lld\n", ans);
        }
    }

    printf("%lld\n", ans);
    
}
