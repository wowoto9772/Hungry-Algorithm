#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll lmod = 1000000007;

class BIT{
    public:
        vector <ll> T;
        int S;

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

int main(){

    int n;
    scanf("%d", &n);

    int lst = 200001;

    BIT tree(lst), cnt(lst);

    ll ans = 1;
    for(int i=1; i<=n; i++){
        int v;
        scanf("%d", &v);
        v++;
        if(i > 1){
            ll cst1 = cnt.Sum(v-1) * v - tree.Sum(v-1);
            ll cst2 = (tree.Sum(lst) - tree.Sum(v)) - (cnt.Sum(lst) - cnt.Sum(v)) * v;
            ll cst = (cst1 + cst2) % lmod;
            ans *= cst;
            ans %= lmod;
        }
        tree.Update(v, v);
        cnt.Update(v, 1);
    }

    printf("%lld\n", ans);

}
