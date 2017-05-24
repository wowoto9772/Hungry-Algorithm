#include <cstdio>

using namespace std;
using ll = long long;

ll e[203];

int main(){
    
    int t;
    scanf("%d", &t);
    
    int tc = 0;
    
    while(t--){
        
        int n;
        scanf("%d", &n);
        
        printf("Case #%d: ", ++tc);

        for(int i=1; i<=2*n; i++)scanf("%lld", &e[i]);
        bool chk[203] = {};
        
        ll ans[203] = {};
        int top = 0;
        
        for(int i=2*n; i>=1; i--){
            if(chk[i])continue;
            chk[i] = true;
            for(int j=i-1; j>=1; j--){
                if(((e[i]*3) / 4 == e[j]) && !chk[j]){
                    chk[j] = true;
                    ans[top++] = e[j];
                    break;
                }
            }
        }
        
        for(int i=top-1; i>=0; i--)printf("%lld ", ans[i]);
        printf("\n");
        
    }

}