#include <stdio.h>

#include <vector>

using namespace std;

using ll = long long;

class BIT{
    public:
        vector <int> T;
        int S;

        BIT(const int n){
            S = n;
            T.resize(S + 1);
        }

        void Update(int p, int v){
            while (p <= S){
                T[p] += v;
                p += p & (-p);
            }
        }

        ll Sum(int p){
            if(p == 0)return 0LL;
            ll ret = 0;
            while (p > 0){
                ret += T[p];
                p -= p & (-p);
            }return ret;
        }

};

int e[500003];

int main(){

    int n;
    scanf("%d", &n);

    BIT le(n), ri(n);

    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        ri.Update(e[i], 1);
    }

    ll ans = 0;

    for(int i=1; i<=n; i++){

       ri.Update(e[i], -1);

       ans += (le.Sum(n) - le.Sum(e[i])) * (ri.Sum(e[i]-1));

       le.Update(e[i], 1);
 
    }

    printf("%lld\n", ans);

}
