#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

const int INT_MAX = (1<<31)-1;

class ele{
    public:
        int r, c, s, m;
        ele(){}
        ele(int _r, int _c, int _s, int _m){
            r = _r, c = _c, s = _s, m = _m;
        }

        bool operator<(const ele &A)const{
            return m > A.m;
        }

};

int d[1003][1003][2], x[1003][1003];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    int s, e, a, b;
    scanf("%d %d %d %d", &s, &e, &a, &b);

    for(int i=1; i<=r; i++)for(int j=1; j<=c; j++){
        d[i][j][0] = d[i][j][1] = INT_MAX;
        scanf("%d", &x[i][j]);
    }

    d[s][e][1] = 0;

    priority_queue <ele> q;
    q.emplace(s, e, 1, 0);

    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(d[f.r][f.c][f.s] < f.m)continue;
        for(int i=0; i<4; i++){
            ele g = {f.r + dr[i], f.c + dc[i], f.s, f.m + 1};
            if(g.r < 1 || g.r > r || g.c < 1 || g.c > c)continue;
            if(x[g.r][g.c] == 1){
                if(g.s){
                    g.s = 0;
                    if(d[g.r][g.c][g.s] > g.m){
                        d[g.r][g.c][g.s] = g.m;
                        q.emplace(g);
                    }
                }
            }else{
                if(d[g.r][g.c][g.s] > g.m){
                    d[g.r][g.c][g.s] = g.m;
                    q.emplace(g);
                }
            }
        }
    }

    int ans = min(d[a][b][0], d[a][b][1]);
    if(ans == INT_MAX)ans = -1;

    printf("%d\n", ans);

}
