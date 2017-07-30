#include <cstdio>
#include <algorithm>
#include <queue>

using ll = long long;
ll lmax = (1LL<<63)-1;
using namespace std;

class ele{
public:
    int r, c, m;
    ll v;
    ele(){}
    ele(int _r, int _c, int _m, ll _v){
        r = _r, c = _c, m = _m, v = _v;
    }
    bool operator<(const ele &A)const{
        return v > A.v;
    }
};

ll c[103][103][4];
int e[103][103];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){
    
    int n, t;
    scanf("%d %d", &n, &t);
    
    for(int i=0; i<n; i++)for(int j=0; j<n; j++){
        for(int k=0; k<3; k++){
            c[i][j][k] = lmax;
        }
        scanf("%d", &e[i][j]);
    }
    
    priority_queue < ele > q;
    c[0][0][0] = 0;
    q.emplace(0,0,0,0);
    
    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(c[f.r][f.c][f.m] < f.v)continue;
        for(int i=0; i<4; i++){
            ele g = {f.r + dr[i], f.c + dc[i], f.m+1, f.v+t};
            if(g.r < 0 || g.r >= n || g.c < 0 || g.c >= n)continue;
            if(g.m == 3){
                g.v += e[g.r][g.c];
                g.m = 0;
            }
            if(c[g.r][g.c][g.m] > g.v){
                c[g.r][g.c][g.m] = g.v;
                q.emplace(g);
            }
        }
    }
    
    ll ans = lmax;
    for(int i=0; i<3; i++)ans = min(ans, c[n-1][n-1][i]);
    printf("%lld\n", ans);

}