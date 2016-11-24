#include <cstdio>
#include <limits.h>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

class ele{
    public:
        int a, b, c;
        ele(){}
        ele(int _a, int _b, int _c){
            a = _a, b = _b, c = _c;
        }
};

ll d[1003][1003];

int main(){

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    int st, dt;
    scanf("%d %d", &st, &dt);

    vector < ele > edge;
    edge.resize(m);

    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[i] = {a, b, c};
    }

    for(int i=1; i<=n; i++)for(int j=0; j<n; j++)d[i][j] = LLONG_MAX;

    ll fst = LLONG_MAX;

    d[st][0] = 0;
    for(int i=1; i<n; i++){
        for(auto &e : edge){
            if(d[e.b][i-1] != LLONG_MAX){
                d[e.a][i] = min(d[e.a][i], d[e.b][i-1] + e.c);
            }
            if(d[e.a][i-1] != LLONG_MAX){
                d[e.b][i] = min(d[e.b][i], d[e.a][i-1] + e.c);
            }
        }
        fst = min(fst, d[dt][i]);
    }

    printf("%lld\n", fst);

    for(int i=1; i<=q; i++){
        int x;
        scanf("%d", &x);
        for(int j=1; j<n; j++){
            if(d[dt][j] != LLONG_MAX)d[dt][j] += j*x;
        }

        ll ans = LLONG_MAX;
        for(int j=1; j<n; j++){
            ans = min(ans, d[dt][j]);
        }
        printf("%lld\n", ans);
    }

}
