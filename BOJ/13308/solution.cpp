#include <cstdio>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;

class ele{
    public:
        int h, i;
        ll c;
        ele(){}
        ele(int _h, ll _c, int _i){
            h = _h, c = _c, i = _i;
        }

        bool operator<(const ele &A)const{
            if(c == A.c)return h > A.h;
            return c > A.c;
        }
};

int c[2503];
ll d[2503][2503];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        scanf("%d", &c[i]);
    }

    vector < vector < pair <int,int> > > lnk;
    lnk.resize(n+1);

    for(int i=1; i<=n; i++)for(int j=1; j<=2500; j++)d[i][j] = LLONG_MAX;

    for(int i=1; i<=m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        lnk[a].emplace_back(b, c);
        lnk[b].emplace_back(a, c);
    }

    priority_queue <ele> q;
    q.emplace(c[1], 0, 1);
    d[1][c[1]] = 0;

    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(d[f.i][f.h] < f.c)continue;
        for(auto &e : lnk[f.i]){
            int nh = min(f.h, c[e.first]);
            if(d[e.first][nh] > f.c + e.second * f.h){
                d[e.first][nh] = f.c + e.second * f.h;
                ele g = {nh, d[e.first][nh], e.first};
                q.emplace(g);
            }
        }
    }

    ll ans = LLONG_MAX;
    for(int i=1; i<=2500; i++)ans = min(ans, d[n][i]);

    printf("%lld\n", ans);

}
