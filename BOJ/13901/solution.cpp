#include <cstdio>

using namespace std;

bool cant[1003][1003];
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
int z[4];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    int k;
    scanf("%d", &k);

    for(int i=1; i<=k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        cant[x][y] = true;
    }

    int x, y;
    scanf("%d %d", &x, &y);

    cant[x][y] = true;

    bool ign = false;

    for(int i=0; i<4; i++){
        scanf("%d", &z[i]);
        z[i]--;
    }

    int i = 0, j = 0;

    while(true){
        int nx = x + dr[z[i]], ny = y + dc[z[i]];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || cant[nx][ny]){
            i++;
            if(i == 4){
                if(j == 0)break;
                i = j = 0;
            }
            continue;
        }
        else{
            x = nx, y = ny;
            cant[x][y] = true;
            j++;
        }
    }

    printf("%d %d\n", x, y);

}
