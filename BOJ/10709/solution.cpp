#include <stdio.h>

char str[103][103];
int cc[103][103];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++){
        scanf("%s", str[i]);
        for(int j=0; j<c; j++)cc[i][j] = -1;
    }

    for(int i=0; i<r; i++){
        for(int j=c-1; j>=0; j--){
            if(str[i][j] == 'c'){
                if(cc[i][j] == -1){
                    cc[i][j] = 0;
                    for(int k=j+1; k<c; k++){
                        if(cc[i][k] == -1){
                            cc[i][k] = cc[i][k-1]+1;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)printf("%d ", cc[i][j]);
        printf("\n");
    }

}
