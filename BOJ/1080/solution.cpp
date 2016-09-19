#include <stdio.h>

char a[63][63];
char b[63][63];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++)scanf("%s", a[i]);
    for(int i=0; i<r; i++)scanf("%s", b[i]);

    int d = 0;

    for(int i=0; i<r-2; i++){
        for(int j=0; j<c-2; j++){
            if(a[i][j] == b[i][j])continue;
            d++;
            for(int x=i; x<=i+2; x++){
                for(int y=j; y<=j+2; y++){
                    if(a[x][y] == '1')a[x][y] = '0';
                    else
                        a[x][y] = '1';
                }
            }
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j] != b[i][j]){
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", d);

}
