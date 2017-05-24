#include <cstdio>
#include <limits.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
using ll = long long;

const ll lmod = 1000000009;

class ele{
    public:
        int a;
        ll c;
        ele(){}
        ele(int _a, ll _c){a=_a, c=_c;}
        
        bool operator<(const ele &A)const{
            return c > A.c;
        }
};

ll dist[100003];
ll cnt[100003];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)dist[i] = LLONG_MAX;
    
    vector < vector < ele > > edge;
    edge.resize(n+1);

    int start, goal;
    scanf("%d %d", &start, &goal);

    while(m--){
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        edge[a].emplace_back(b, c);
        edge[b].emplace_back(a, c);
    }

    priority_queue <ele> q;
    q.emplace(start, 0);
    dist[start] = 0;
    cnt[start] = 1;

    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(dist[f.a] < f.c)continue;
        for(auto &e : edge[f.a]){
            if(dist[e.a] > e.c + f.c){
                dist[e.a] = e.c + f.c;
                cnt[e.a] = cnt[f.a];
                q.emplace(e.a, dist[e.a]);
            }else if(dist[e.a] == e.c + f.c){
                cnt[e.a] += cnt[f.a];
                cnt[e.a] %= lmod;
            }
        }
    }

    printf("%lld\n", cnt[goal]);

}
