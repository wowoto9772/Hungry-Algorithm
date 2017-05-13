#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
    public:
        int s, t, c;
        ele(){}
        ele(int _s, int _t, int _c){
            s = _s, t = _t, c = _c;
        }
};

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int s, t;
        scanf("%d %d", &s, &t);

        queue <ele> q;
        q.emplace(s, t, 0);

        bool chk[204][204] = {};

        while(!q.empty()){
            ele f = q.front(); q.pop();
            if(f.s == f.t){
                printf("%d\n", f.c);
                break;
            }
            ele g = {f.s+f.s, f.t+3, f.c+1};
            if(g.s <= g.t){
                if(!chk[g.s][g.t]){
                    chk[g.s][g.t] = true;
                    q.emplace(g);
                }
            }
            g = {f.s+1, f.t, f.c+1};
            if(!chk[g.s][g.t]){
                chk[g.s][g.t] = true;
                q.emplace(g);
            }
        }
    }

}
