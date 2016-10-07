#include <cstdio>

using namespace std;

char str[13][13];
char tmp[13][13];

int dr[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dc[] = {-1, 1, -1, 0, 1, -1, 0, 1};

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }

    bool bomb = false;

    for(int i=0; i<n; i++){
        scanf("%s", tmp[i]);
        for(int j=0; j<n; j++){
            if(tmp[i][j] == 'x'){
                if(str[i][j] == '*')bomb = true;
                else{
                    int v = '0';
                    for(int k=0; k<8; k++){
                        int ni = i + dr[k], nj = j + dc[k];
                        if(ni < 0 || nj < 0 || ni >= n || nj >= n)continue;
                        if(str[ni][nj] == '*')v++;
                    }
                    tmp[i][j] = v;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if(bomb)for(int j=0; j<n; j++)if(str[i][j] == '*')tmp[i][j] = '*';
        printf("%s\n", tmp[i]);
    }

}
