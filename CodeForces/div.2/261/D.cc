#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

struct BIT{
    int S;
    vector <int> T;

    BIT(int n){
        S = n, T.resize(n+1);
    }

    void Update(int p, int v){
        while (p <= S){
            T[p] += v;
            p += p & (-p);
        }
    }

    ll Sum(int p){
        ll ret = 0;
        while (p > 0){
            ret += T[p];
            p -= p & (-p);
        }
        return ret;
    }
};

int e[1000003], r[1000003];

int main(){

    int n;
    scanf("%d", &n);

    map <int, int> cnt;

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    BIT rdt(n);
    for(int i=n; i>=1; i--){
        r[i] = ++cnt[e[i]];
        rdt.Update(r[i], 1);
    }

    cnt.clear();

    ll ans = 0;
    for(int i=1; i<=n; i++){
        rdt.Update(r[i], -1);
        cnt[e[i]]++;
        ans += rdt.Sum(cnt[e[i]]-1);
    }

    printf("%lld\n", ans);

}
