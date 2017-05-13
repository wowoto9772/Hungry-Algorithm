#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int in[1003], t[1003];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    vector < vector < int> > nxt;
    nxt.resize(n+1);

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        in[b]++;
        nxt[a].push_back(b);
    }

    queue < pair<int,int> > q;
    for(int i=1; i<=n; i++){
        if(in[i] == 0){
            q.emplace(i, 1);
            t[i] = 1;
        }
    }

    while(!q.empty()){
        pair<int,int> f = q.front();q.pop();
        for(auto &e : nxt[f.first]){
            if(--in[e] == 0){
                q.emplace(e, f.second+1);
                t[e] = f.second+1;
            }
        }
    }   
    
    for(int i=1; i<=n; i++)printf("%d ", t[i]);

}
