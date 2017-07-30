#include <cstdio>
#include <cstring>

using namespace std;
#define ll long long

char str[10];

ll calc(char *a, int n, int l){
    ll r = 1;
    if(!strcmp(a, "O(N)"))r = n;
    else if(!strcmp(a, "O(N^2)"))r = (ll)n*n;
    else if(!strcmp(a, "O(N^3)")){
        r = (ll)n*n*n;
    }else if(!strcmp(a, "O(2^N)")){
        r = 1;
        while(n--){
            r <<= 1;
            if(r > l)break;
        }
    }else{
        while(n){
            r *= n--;
            if(r > l)break;
        }
    }
    return r;
}

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n, tc, l;
        scanf("%s %d %d %d", str, &n, &tc, &l);
        l *= 1e8;
        
        ll p = calc(str, n, l);
        
        ll c = 0;
        for(int i=1; i<=tc && c <= l; i++){
            c += p;
        }
        
        if(c > l)printf("TLE!");
        else
            printf("May Pass.");
        
        printf("\n");
    }

}