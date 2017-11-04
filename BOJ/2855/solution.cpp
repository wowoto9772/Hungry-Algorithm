#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

ll e[100003], s[100003];
int pr[100003], pl[100003], ans[100003];

int main(){
    
    int n;
    ll S;
    scanf("%d %lld", &n, &S);
    
    for(int i=1; i<=n; i++){
        scanf("%lld", &e[i]);
    }
    
    for(int i=1; i<=n; i++)s[i] = s[i-1] + e[i];   
    for(int i=1; i<=n; i++)pr[i] = (upper_bound(s, s+n+1, s[i-1]+S)-s) - i;

    for(int i=1; i<=n; i++)s[i] = s[i-1] + e[n+1-i];
    for(int i=1; i<=n; i++)pl[n+1-i] = (upper_bound(s, s+n+1, s[i-1]+S)-s) - i;
    
    for(int i=1; i<n; i++){
        ans[i] = min(pl[i], pr[i+1]);
        if(ans[i] > 1){
            ans[i+1-ans[i]] = ans[i];
            ans[i] = 0;
        }
    }
    
    int x = 0;
    ans[n] = 0;
    for(int i=1; i<=n; i++){
        if(x < ans[i])x = ans[i];
        printf("%d\n", x<<1);
        x--;
    }

}
