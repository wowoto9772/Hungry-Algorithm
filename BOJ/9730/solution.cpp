#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main(){
     
    int t;
    scanf("%d", &t);
     
    int tc = 0;
     
    while(t--){
         
        int n;
        scanf("%d", &n);
         
        int p, e;
         
        int ans = 0;
         
        for(int i=1; i<=n; i++){
            scanf("%d", &e);
            if(i > 1)ans += max(p, e);
            p = e;
        }
         
        printf("Case #%d: %d\n", ++tc, ans);
     
    }
 
}