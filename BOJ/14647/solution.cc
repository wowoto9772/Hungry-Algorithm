#include <stdio.h>

int x[503], y[503], z;

int main(){
    
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int v;
            scanf("%d", &v);
            while(v){
                if(v%10 == 9){
                    x[i]++, y[j]++;
                    z++;   
                }
                v /= 10;
            }
        }
    }
    
    int w = 0;
    for(int i=0; i<r; i++){
        if(w < x[i])w = x[i];
    }
    for(int i=0; i<c; i++){
        if(w < y[i])w = y[i];
    }
    
    printf("%d\n", z - w);

}