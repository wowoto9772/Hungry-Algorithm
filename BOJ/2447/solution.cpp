#include <stdio.h>

char str[6563][6563];

void star(int x, int y, int s){
    if(s == 3){
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                str[i][j] = '*';
            }
        }
        str[x+1][y+1] = 0;
    }else{
        int e = s / 3;
        star(x, y, e);
        star(x+e, y, e);
        star(x+2*e, y, e);
        star(x, y+e, e);
        star(x+2*e, y+e, e);
        star(x, y+2*e, e);
        star(x+e, y+2*e, e);
        star(x+2*e, y+2*e, e);
    }
}

int main(){

    int n;
    scanf("%d", &n);

    if(n == 1){
        printf("*");
        return 0;
    }

    star(0, 0, n);

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            if(str[i][j] == 0)str[i][j] = ' ';
            printf("%c", str[i][j]);
        }

        printf("\n");

    }

}
