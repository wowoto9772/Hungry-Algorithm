#include <stdio.h>

#include <queue>

using namespace std;

class ele{
    public:

        int x, y, z, m;

        ele(){}
        ele(int _x, int _y, int _z, int _m){
            x = _x, y = _y, z = _z, m = _m;
        }

};

char str[33][33][33];

bool chk[33][33][33];

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

int main(){

    int r, c, n;
    while(scanf("%d %d %d", &n, &r, &c) == 3){

        if(((r|c)|n) == 0)break;

        ele S;

        for(int i=0; i<n; i++){
            
            for(int j=0; j<r; j++){
                scanf("%s", str[i][j]);
                for(int k=0; k<c; k++){
                    if(str[i][j][k] == 'S'){
                        S = {j, k, i, 0};
                    }
                    chk[i][j][k] = false;
                }
            }

        }

        queue <ele> q;

        q.emplace(S);

        int ret = -1;

        while(!q.empty()){

            ele f = q.front(); q.pop();

            if(str[f.z][f.x][f.y] == 'E'){
                ret = f.m;
                break;
            }

            for(int i=0; i<6; i++){

                ele g = {f.x + dx[i], f.y + dy[i], f.z + dz[i], f.m+1};

                if(g.x < 0 || g.x >= r || g.y < 0 || g.y >= c || g.z < 0 || g.z >= n)continue;

                if(chk[g.z][g.x][g.y])continue;

                if(str[g.z][g.x][g.y] == '#')continue;

                chk[g.z][g.x][g.y] = true;

                q.emplace(g);

            }

        }

        if(ret != -1)printf("Escaped in %d minute(s).\n", ret);
        else
            printf("Trapped!\n");

    }

}
