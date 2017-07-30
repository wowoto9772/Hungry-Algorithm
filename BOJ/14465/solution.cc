#include <cstdio>

using namespace std;

int c[100003];

int main(){
    
    int n, k, b;
    scanf("%d %d %d", &n, &k, &b);
    
    while(b--){
        int v;
        scanf("%d", &v);
        c[v] = 1;
    }
    
    int ans = k;
    
    for(int i=1; i<=n; i++){
        c[i] += c[i-1];
        if(i >= k){
            if(ans > c[i] - c[i-k])ans = c[i] - c[i-k];
        }
    }
    
    printf("%d\n", ans);
    
}