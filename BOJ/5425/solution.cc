#include <cstdio>

using namespace std;
using ll = long long;

ll c;

void calc(ll v, ll t){
    while(v){
        c += (v%10)*t;
        v /= 10;
    }
}

void proc(ll s, ll e, ll t){
    while(s%10 && s <= e){
        calc(s, t);
        s++;
    }
    if(s > e)return ;
    while(e%10 < 9 && s <= e){
        calc(e, t);
        e--;
    }
    ll cnt = (e/10-s/10)+1;
    for(int i=0; i<10; i++)c += cnt*t*i;
    proc(s/10, e/10, t*10LL);
}

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){

        ll s, e;
        scanf("%lld %lld", &s, &e);
    
        if(s == 0)s = 1;

        c = 0;
        proc(s, e, 1);

        printf("%lld\n", c);
        
    }

}