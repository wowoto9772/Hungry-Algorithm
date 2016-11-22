#include <cstdio>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;

int d[2][10003];

int main(){

    int v, m;
    scanf("%d %d", &v, &m);

    vector < vector < pair<int,int> > >lnk;
    lnk.resize(v+1);

    for(int i=1; i<=m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        lnk[a].emplace_back(b, c);
        lnk[b].emplace_back(a, c);
    }

    vector <int> D[2];
    int C[2], s, c;
    scanf("%d %d", &c, &C[0]);
    D[0].resize(c);

    vector <bool> cant;
    cant.resize(v+1);
    for(int i=0; i<c; i++){
        scanf("%d", &D[0][i]);
        cant[D[0][i]] = true;
    }
    scanf("%d %d", &c, &C[1]);
    D[1].resize(c);
    for(int i=0; i<c; i++){
        scanf("%d", &D[1][i]);
        cant[D[1][i]] = true;
    }

    for(int i=0; i<2; i++){
        for(int j=1; j<=v; j++)d[i][j] = INT_MAX;
        priority_queue < pair<int,int>, vector< pair<int,int> >, greater < pair<int,int> > > q;
        for(auto &e : D[i]){
            d[i][e] = 0;
            q.emplace(0, e);
        }

        while(!q.empty()){
            pair<int,int> f = q.top(); q.pop();
            if(d[i][f.second] < f.first)continue;
            for(auto &e : lnk[f.second]){
                if(d[i][e.first] > f.first + e.second){
                    d[i][e.first] = f.first + e.second;
                    q.emplace(d[i][e.first], e.first);
                }
            }
        }
    }

    int ans = INT_MAX;

    for(int i=1; i<=v; i++){
        if(cant[i])continue;
        if(d[0][i] <= C[0] && d[1][i] <= C[1]){
            ans = min(ans, d[0][i] + d[1][i]);
        }
    }

    if(ans == INT_MAX)ans = -1;
    printf("%d\n", ans);

}
