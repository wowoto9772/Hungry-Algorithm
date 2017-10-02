#include <cstdio>
#include <cstring>

using namespace std;

using ll = long long;

char k[73];
ll n;

ll solv(int c){
    if(c == 0)return 0;
    int p = c;
    ll ret = 0, t = 1;
    for(int i=c; i>=1 && t<n; i--){
        if(ret+(k[i]-'0')*t >= n)break;
        ret += (k[i]-'0')*t;
        t *= 10LL;
        if(k[i] == '0')continue;
        else
            p = i; // prevent leading zeroes.
    }
    return solv(--p) * n + ret;
}

int main(){
    
    scanf("%lld", &n);
    
    scanf("%s", k+1);
    int m = strlen(k+1);
    
    printf("%lld\n", solv(m));

}