#include <cstdio>

using namespace std;

char ans[253][253];
char str[53][53];

int main(){

    int r, c, zr, zc;
    scanf("%d %d %d %d", &r, &c, &zr, &zc);

    for(int i=0; i<r; i++)scanf("%s", str[i]);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int a=i*zr; a<=i*zr+zr-1; a++){
                for(int b=j*zc; b<=j*zc+zc-1; b++){
                    ans[a][b] = str[i][j];
                }
            }
        }
    }

    for(int i=0; i<r*zr; i++){
        printf("%s\n", ans[i]);
    }

}
