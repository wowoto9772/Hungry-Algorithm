#include <cstdio>

using namespace std;
using ll = long long;

ll d[1000003];

int main(){
    
    for(int i=1; i<=1000000; i++)d[i] = d[i-1] + (ll) i*i;
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", d[n]);
    }

}