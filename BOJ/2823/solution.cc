#include <cstdio>
#include <queue>

using namespace std;

char str[13][13];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++)scanf("%s", str[i]);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(str[i][j] == '.'){
                int z = 0;
                for(int k=0; k<4; k++){
                    int x = i+dr[k], y = j+dc[k];
                    if(x < 0 || y < 0 || x >= r || y >= c || str[x][y] != '.')continue;
                    z++;
                }
                if(z <= 1){
                    printf("1");
                    return 0;
                }
            }
        }
    }
    printf("0");

}
