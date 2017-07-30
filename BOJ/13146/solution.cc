#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;

int e[1000003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    int maxV = 0;
    ll ans = 0;
    
    for(int i=0; i<n; i++){
        scanf("%d", &e[i]);
        if(maxV < e[i]){
            maxV = e[i];
        }
        if(i >= 1)ans += abs(e[i] - e[i-1]);   
    }
    
    ans += abs(e[0] - maxV) + abs(e[n-1] - maxV);
    printf("%lld\n", ans>>1);

}