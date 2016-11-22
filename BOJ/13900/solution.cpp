#include <cstdio>
#include <vector>

using ll = long long;
using namespace std;

// Author : wowoto9772

class BIT{
    public:
        vector <int> T;
        int S;

        BIT(int n) : S(n), T(n+1) {}

        void Update(int p, int v){
            if(p == 0)return ;
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

int e[100003];

int main(){

    int n;
    scanf("%d", &n);

    BIT tree(10000);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        tree.Update(e[i], e[i]);
    }

    ll ans = 0;

    for(int i=1; i<=n; i++){
        tree.Update(e[i], -e[i]);
        ans += tree.Sum(10000) * e[i];
    }

    printf("%lld\n", ans);

}
