#include <cstdio>

using namespace std;

int e[103];

int main(){
    
    int n;
    scanf("%d", &n);
    
    int ans = 0, maxv = 0;
    
    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        if(maxv < e[i])maxv = e[i];
    }
    
    for(int i=1; i<=n; i++)ans += maxv - e[i];
    printf("%d\n", ans);

}