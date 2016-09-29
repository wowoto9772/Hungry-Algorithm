#include <stdio.h>

using ll = long long;

ll modpower(ll a, ll p, ll m){
    ll r = 1;
    while(p){
        if(p&1)r = (r*a) % m;
        a = (a*a) % m;
        p >>= 1;
    }
    return r;
}

bool isPrime(int v){
    if(v == 2)return true;
    else{
        if(v%2 == 0)return false;
        for(int j=3; j*j <= v; j+=2){
            if(!(v%j))return false;
        }
        return true;
    }
}

int main(){

    // a ^ p == a
    
    int a, p;
    
    while(scanf("%d %d", &p, &a) == 2){
        
        if(!(a|p))break;

        if(modpower(a, p, p) == a){
            if(isPrime(p))printf("no\n");
            else
                printf("yes\n");
        }else{
            printf("no\n");
        }

    }

}
