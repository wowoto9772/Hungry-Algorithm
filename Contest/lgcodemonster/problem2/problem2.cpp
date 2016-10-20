#include <cstdio>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;

using namespace std;

class ele{
    public:
    int a, b, c;
    
    ele(){}
    ele(int _a, int _b, int _c){
        a = _a, b = _b, c = _c;
    }

    bool operator<(const ele &A)const{
        return c > A.c;
    }

};

int p[10003], d[10003];
int findParent(int my){
    if(p[my] == my)return my;
    return p[my] = findParent(p[my]);
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    
    while(t--){

        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++)p[i] = i;

        vector < ele > edge(m);

        for(int i=0; i<m; i++){

            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            edge[i] = {a, b, c};

        }

        sort(edge.begin(), edge.end());

        vector < vector < pair<int,int> > > lnk;
        lnk.resize(n+1);

        for(int i=0; i<edge.size(); i++){

            int a = edge[i].a, b = edge[i].b;

            if(findParent(a) == findParent(b))continue;

            p[findParent(a)] = findParent(b);

            lnk[edge[i].a].emplace_back(edge[i].b, edge[i].c);
            lnk[edge[i].b].emplace_back(edge[i].a, edge[i].c);

        }

        int qry;
        scanf("%d", &qry);

        vector < vector <int> > query;

        query.resize(n+1);

        while(qry--){

            int a, b;
            scanf("%d %d", &a, &b);

            query[a].push_back(b);
            query[b].push_back(a);

        }

        ll tot = 0;

        for(int i=1; i<=n; i++){
            if(query[i].empty())continue;

            queue <int> q;
            q.push(i);

            for(int j=1; j<=n; j++)d[j] = 0;
            d[i] = INT_MAX;

            while(!q.empty()){
                
                int f = q.front(); q.pop();

                for(int j=0; j<lnk[f].size(); j++){
                    int g = lnk[f][j].first, c = lnk[f][j].second;
                    if(d[g] == 0){
                        d[g] = min(d[f], c);
                        q.emplace(g);
                    }
                }
            }

            for(auto &e : query[i]){
                if(e == i)continue;
                tot += d[e];
            }

        }

        printf("%lld\n", tot >> 1);

    }

}
