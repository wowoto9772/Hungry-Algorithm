#include <cstdio>

using namespace std;

int p[103];
int e[103];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=100; i++)p[i] = -1;
    
    for(int i=1; i<=n; i++){

        int x, y;
        scanf("%d %d", &x, &y);    
        p[x] = y;
        
    }
    
    int m;
    scanf("%d", &m);
    
    while(m--){
        int c;
        scanf("%d", &c);
        bool flag = true;
        for(int i=0; i<c; i++){
            scanf("%d", &e[i]);
            flag &= (p[e[i]] != -1);
        }
        if(flag){
            for(int i=0; i<c; i++)printf("%d ", p[e[i]]);
        }else{
            printf("YOU DIED");
        }
        printf("\n");
    }

}