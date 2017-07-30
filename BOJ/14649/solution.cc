#include <stdio.h>

int x[103];

int main(){
    
    int p, n;
    scanf("%d %d", &p, &n);
    
    while(n--){
        int v;
        char c;
        scanf("%d %c", &v, &c);
        if(c == 'L'){
            for(int i=1; i<=v-1; i++)x[i]++;
        }else{
            for(int i=v+1; i<=100; i++)x[i]++;
        }
    }
    
    int y[3] = {};
    for(int i=1; i<=100; i++)y[x[i]%3]++;
    for(int i=0; i<3; i++)printf("%.2lf\n", (double)p * y[i] / 100);

}