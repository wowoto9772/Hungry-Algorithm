#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class ele{
public:
    int a, c;
    ele(){}
    ele(int _a, int _c){
        a = _a, c = _c;
    }
    bool operator<(const ele &A)const{
        return c > A.c;
    }
};

int d[10003];

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n, m, c;
        scanf("%d %d %d", &n, &m, &c);
        
        vector < vector < ele > > lnk;
        lnk.resize(n+1);
        while(m--){
            int a, b, s;
            scanf("%d %d %d", &a, &b, &s);
            lnk[b].emplace_back(a, s);
        }
        
        for(int i=1; i<=n; i++)d[i] = (1<<31)-1;
        priority_queue < ele > q;
        q.emplace(c, 0);
        d[c] = 0;
        
        while(!q.empty()){
            ele f = q.top(); q.pop();
            if(d[f.a] < f.c)continue;
            for(int i=0; i<lnk[f.a].size(); i++){
                ele g = lnk[f.a][i];
                g.c += f.c;
                if(d[g.a] > g.c){
                    d[g.a] = g.c;
                    q.emplace(g);
                }
            }
        }
                
        int x = 0, y = 0;
        for(int i=1; i<=n; i++)if(d[i] != (1<<31)-1){
            if(y < d[i])y = d[i];
            x++;
        }
        
        printf("%d %d\n", x, y);
        
    }

}