#include <cstdio>

using namespace std;

// 동, 서, 북, 남
int dd[4][6] = {{4,1,0,3,5,2}, {2,1,5,3,0,4}, {1,5,2,0,4,3}, {3,0,2,5,4,1}};
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
// 상, 후, 좌, 전, 우, 하
int dice[] = {0,0,0,0,0,0};
int e[23][23];

int main(){
    
    int r, c, x, y, k;
    scanf("%d %d %d %d %d", &r, &c, &x, &y, &k);
    
    for(int i=0; i<r; i++)for(int j=0; j<c; j++)scanf("%d", &e[i][j]);
        
    dice[5] = e[x][y];
    e[x][y] = 0;
        
    while(k--){
        int v;
        scanf("%d", &v);
        v--;
        int nx = x+dx[v], ny = y+dy[v];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
        int ndice[6];
        for(int i=0; i<6; i++)ndice[dd[v][i]] = dice[i];
        for(int i=0; i<6; i++)dice[i] = ndice[i];
        
        if(e[nx][ny]){
            dice[5] = e[nx][ny];
            e[nx][ny] = 0;   
        }else{
            e[nx][ny] = dice[5];
        }
        
        x = nx, y = ny;
        printf("%d\n", dice[0]);
    }
    
}