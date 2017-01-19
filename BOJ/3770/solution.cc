#include <cstdio>

#include <vector>
#include <algorithm>

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
            ll ret = 0;
            while (p > 0){
                ret += T[p];
                p -= p & (-p);
            }return ret;
        }
};

int main()
{
    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){

        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        vector < pair <int,int> > e(k);

        for (int i = 0; i < k; i++){
            scanf("%d %d", &e[i].first, &e[i].second);
        }

        BIT S(m);

        sort(e.begin(), e.end());

        ll ans = 0;

        for (int i = e.size()-1; i >= 0; i--){
            ans += S.Sum(e[i].second-1); 

            // count that X greater than or equal to e[i].x and Y less than e[i].y
            S.Update(e[i].second, 1);
        }

        printf("Test case %d: %lld\n", ++tc, ans);
    }
}
