#include <cstdio>
#include <memory.h>

using namespace std;

const int imod = 31991;

int main(){

    int d, t;
    scanf("%d %d", &d, &t);

    int mat[53][53] = {};
    int out[53][53] = {};

    for(int i=0; i<d; i++){
        mat[0][i] = 1;
        if(i)mat[i][i-1] = 1;
        out[i][i] = 1;
    }

    while(t){
        if(t&1){
            int tmp[53][53] = {};
            for(int k=0; k<d; k++){
                for(int i=0; i<d; i++){
                    for(int j=0; j<d; j++){
                        tmp[i][j] += out[i][k]*mat[k][j];
                        tmp[i][j] %= imod;
                    }
                }
            }
            memcpy(out, tmp, sizeof(tmp));
        }
        int tmp[53][53] = {};
        for(int k=0; k<d; k++){
            for(int i=0; i<d; i++){
                for(int j=0; j<d; j++){
                    tmp[i][j] += mat[i][k]*mat[k][j];
                    tmp[i][j] %= imod;
                }
            }
        }
        memcpy(mat, tmp, sizeof(tmp));
        t >>= 1;
    }

    printf("%d\n", out[0][0]);

}
