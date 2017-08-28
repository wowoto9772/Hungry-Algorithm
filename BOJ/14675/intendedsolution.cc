#include <cstdio>

using namespace std;

int c[100003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        c[u]++, c[v]++;
    }
    
    int q;
    scanf("%d", &q);
    
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        
        int x = 1;
        
        if(a == 1){
            if(c[b] == 1)x = 0;
        }
        
        printf("%s\n", (x&1) ? "yes" : "no");
    }

}