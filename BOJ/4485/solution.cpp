#include <cstdio>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

class ele{
    public:
        int x, y, c;

        ele(){}
        ele(int _x, int _y, int _c){
            x = _x, y = _y, c = _c;
        }

        bool operator<(const ele &A)const{
            return c > A.c;
        }
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int d[128][128], c[128][128];

int main(){

    int tc = 0;

    int n;
    while(scanf("%d", &n) == 1 && n){

        printf("Problem %d: ", ++tc);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d", &c[i][j]);
                d[i][j] = INT_MAX;
            }
        }

        d[1][1] = c[1][1];

        priority_queue <ele> q;

        q.emplace(1,1,c[1][1]);

        while(!q.empty()){

            ele f = q.top(); q.pop();

            if(d[f.x][f.y] < f.c)continue;

            for(int i=0; i<4; i++){
                ele g = {f.x + dx[i], f.y + dy[i], f.c};
                if(g.x < 1 || g.y < 1 || g.x > n || g.y > n)continue;
                g.c += c[g.x][g.y];
                if(d[g.x][g.y] > g.c){
                    d[g.x][g.y] = g.c;
                    q.emplace(g);
                }
            }

        }

        printf("%d\n", d[n][n]);

    }

}
