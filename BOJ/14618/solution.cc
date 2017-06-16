#include <cstdio>
#include <limits.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int e[5003], d[5003];

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    int s;
    scanf("%d", &s);
    
    int k;
    scanf("%d", &k);
    for(int j=-1; j<=1; j+=2){
        for(int i=1; i<=k; i++){
            int v;
            scanf("%d", &v);
            e[v] = j;
        }
    }
    
    vector < vector < pair<int,int> > > edge;
    edge.resize(n+1);
    
    for(int i=1; i<=m; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        edge[x].emplace_back(z, y);
        edge[y].emplace_back(z, x);
    }
    
    for(int i=1; i<=n; i++)d[i] = INT_MAX;
    d[s] = 0;
    
    priority_queue < pair <int,int>, vector < pair <int,int> >, greater < pair <int,int> > > q;
    q.emplace(0, s);
    
    while(!q.empty()){
        pair <int,int> f = q.top(); q.pop();
        if(d[f.second] < f.first)continue;
        for(auto &e : edge[f.second]){
            int c = e.first, a = e.second;
            if(d[a] > f.first + c){
                d[a] = f.first + c;
                q.emplace(d[a], a);
            }
        }
    }
    
    int a = INT_MAX, b = INT_MAX;
    for(int i=1; i<=n; i++){
        if(e[i] == -1)a = min(a, d[i]);
        else if(e[i] == 1)b = min(b, d[i]);
    }
    
    if(a == b){
        if(a == INT_MAX)printf("-1");
        else
            printf("A\n%d", a);
    }else{
        if(a > b)printf("B\n%d", b);
        else
            printf("A\n%d", a);
    }

}