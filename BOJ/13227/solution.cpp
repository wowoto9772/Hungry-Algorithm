#include <cstdio>
using namespace std;

char str[5][5];
int dr[] = {0, 1, 1, 1};
int dc[] = {1, 0, 1, -1};

int main(){

    for(int i=0; i<3; i++)scanf("%s", str[i]);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(str[i][j] != '.'){
                for(int k=0; k<4; k++){
                    int r = i, c = j;
                    int m = 0;
                    while(r >= 0 && r < 3 && c >= 0 && c < 3){
                        if(str[r][c] == str[i][j])m++;
                        else
                            break;
                        r += dr[k];
                        c += dc[k];
                    }

                    if(m == 3){
                        printf("YES\n");
                        return 0;
                    }
                }
            }
        }
    }

    printf("NO\n");

}
