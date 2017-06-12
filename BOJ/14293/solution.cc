#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    
    int t;
    scanf("%d", &t);
    
    int tc = 0;
    
    while(t--){
        
        ll n;
        scanf("%lld", &n);
        
        ll ans = n-1;
        
        for(int i=64; i>=3; i--){
            ll le = pow(n, 1.0 / (double)i);
            ll ri = pow(n, 1.0 / (double)(i-1));
            for(ll d=le; d<=ri; d++){
                int tmp = 0;
                ll v = n;
                for(int j=0; j<=i; j++){
                    tmp += ((v%d) == 1);
                    v /= d;
                }
                if(tmp == i+1){
                    ans = d;
                    break;
                }
            }
        }
        
        printf("Case #%d: %lld\n", ++tc, ans);
        
    }

}