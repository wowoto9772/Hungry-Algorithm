#include <cstdio>

using namespace std;
using ll = long long;

ll a[100003], b[100003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
    }
    
    for(int i=1; i<=n; i++){
        scanf("%lld", &b[i]);
        b[i] += b[i-1];
    }
    
    for(int i=n; i>=0; i--){
        if(a[i] == b[i]){
            printf("%d\n", i);
            return 0;
        }
    }

}