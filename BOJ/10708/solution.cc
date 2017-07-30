#include <stdio.h>

int ans[103];

int main(){
    int n, m;
    scanf("%d %d", &n, &m); 
    for(int i=0; i<m; i++){
        scanf("%d", &ans[i]);
        ans[i]--;
    }
    int c[103] = {};
    int p = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int v;
            scanf("%d", &v);
            v--;
            if(ans[i] == v)c[j]++;
            else
                c[ans[i]]++;
        }
    }
    for(int i=0; i<n; i++)printf("%d\n", c[i]);
    
}