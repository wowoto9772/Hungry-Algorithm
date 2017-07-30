#include <stdio.h>

int c[10003];

int main(){

    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        if((n|m) == 0)break;
        for(int i=1; i<=10000; i++)c[i] = 0;
        int maxv = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int v;
                scanf("%d", &v);
                c[v]++;
                if(c[v] > c[maxv])maxv = v;
            }
        }
        
        int maxv2 = 0;
        for(int i=1; i<=10000; i++){
            if(c[maxv2] < c[i] && c[i] < c[maxv])maxv2 = i;
        }
        
        for(int i=1; i<=10000; i++)if(c[i] == c[maxv2]){
            printf("%d ", i);
        }
        printf("\n");
        
    }

}