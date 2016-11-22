#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, e;
    scanf("%d %d", &n, &e);

    vector < vector < pair<int,int> > > lnk;
    lnk.resize(n+1);

    int src, snk;
    scanf("%d %d", &src, &snk);

    for(int i=1; i<=e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        lnk[a].emplace_back(b, c);
        lnk[b].emplace_back(a, c);
    }

    int ans = 0;

    int l = 1, r = 1000000, m;
    while(l <= r){
        m = (l+r) / 2;
        queue <int> q;
        q.push(src);
        vector <bool> chk(n+1);
        chk[src] = true;
        while(!chk[snk] && !q.empty()){
            int f = q.front(); q.pop();
            for(auto &e : lnk[f]){
                int a = e.first, c = e.second;
                if(chk[a])continue;
                if(m <= c){
                    chk[a] = true;
                    q.emplace(a);
                }
            }
        }
        if(chk[snk]){
            l = m + 1;
            ans = m;
        }else{
            r = m - 1;
        }
    }

    printf("%d\n", ans);

}
