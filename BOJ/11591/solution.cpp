#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

// Author : wowoto9772

class BIT{
    public:
        vector <int> T;
        int S;

        BIT(int n) : S(n), T(n+1) {}

        void Update(int p, int v){
            p++;
            while (p <= S){
                T[p] += v;
                p += p & (-p);
            }
        }

        ll Sum(int p){
            ll ret = 0;
            p++;
            while (p > 0){
                ret += T[p];
                p -= p & (-p);
            }
            return ret;
        }
};

ll s[1000003];

int main(){

    int n;
    scanf("%d", &n);

    vector < pair<ll,int> > v;

    for(int i=1; i<=n; i++){
        scanf("%lld", &s[i]);
    }

    int p;
    scanf("%d", &p);

    for(int i=1; i<=n; i++){
        s[i] -= p;
        s[i] += s[i-1];
        v.emplace_back(s[i], i);
    }

    v.emplace_back(0, 0);
    sort(v.begin(), v.end());

    BIT tree(n+1);

    int l = 0;

    ll ans = 0;

    for(int r=0; r<v.size(); r++){
        while(l < r && (v[r].first - v[l].first >= 0)){
            tree.Update(v[l].second, 1);
            l++;
        }
        ans += tree.Sum(v[r].second);
    }

    printf("%lld\n", ans);

}
