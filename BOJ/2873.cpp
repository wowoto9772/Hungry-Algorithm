#include <cstdio>

using namespace std;

int e[1003][1003];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=1; i<=r; i++)for(int j=1; j<=c; j++)scanf("%d", &e[i][j]);

    if(r&1){
        while(r >= 3){
            for(int j=1; j<c; j++)printf("R");
            printf("D");
            for(int j=1; j<c; j++)printf("L");
            printf("D");
            r -= 2;
        }
        for(int j=1; j<c; j++)printf("R");
    }else if(c&1){
        while(c >= 3){
            for(int j=1; j<r; j++)printf("D");
            printf("R");
            for(int j=1; j<r; j++)printf("U");
            printf("R");
        }
        for(int j=1; j<r; j++)printf("D");
    }else{
        
    }

}
