#include <cstdio>

using namespace std;

int main(){
    
    int tc = 0;
    int n;
    while(scanf("%d", &n) == 1 && n){
                
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                int e;
                scanf("%d", &e);
                if(i == n)ans += e;
                else if(j == 1 || j == i)ans += e;
            }
        }
        
        printf("Case #%d:%d\n", ++tc, ans);
    
    }

}