#include <cstdio>

using namespace std;
using ll = long long;

int main(){
    
    int t;
    scanf("%d", &t);
    
    int tc = 0;
    
    while(t--){
        ll n;
        scanf("%lld", &n);
        
        printf("Case #%d: ", ++tc);
        if(n == 0)printf("INSOMNIA");
        else{
            int c = 0;
            bool chk[10] = {};
            for(ll i=1;;i++){
                ll v = n*i;
                while(v){
                    if(!chk[v%10]){
                        chk[v%10] = true;
                        c++;
                    }
                    v /= 10;
                }
                if(c == 10){
                    printf("%lld", n*i);
                    break;
                }
            }
        }
        printf("\n");
    }

}