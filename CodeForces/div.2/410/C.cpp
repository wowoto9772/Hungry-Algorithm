#include <cstdio>

using namespace std;
using ll = long long;

ll gcd(int a, int b){
    int m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }return a;
}

ll e[100003];

int main(){
    
    int n;
    scanf("%d", &n);
    
    int g;
    for(int i=1; i<=n; i++){
        scanf("%lld", &e[i]);
        if(i == 1)g = e[i];
        else
            g = gcd(g, e[i]);
    }
    
    if(g > 1){
        printf("YES\n0");
        return 0;
    }
    
    int c = 0;
    for(int i=1; i<n; i++){
        while(e[i] & 1){
            c++;
            ll r = e[i+1] + e[i];
            e[i] -= e[i+1];
            e[i+1] = r;
        }
    }
    
    while(e[n] & 1){
        c++;
        ll r = e[n-1] + e[n];
        e[n-1] -= e[n];
        e[n] = r;
    }
        
    printf("YES\n%d", c);
    
}