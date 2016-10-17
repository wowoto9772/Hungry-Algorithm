#include <cstdio>
 
using ll = long long;
using namespace std;
 
ll p[200] = {1, 1, 2, 3};
 
ll func(ll n, int c){
 
    if(n < p[c])return func(n, c-1);
    else if(n == p[c])return n;
    else
        return func(n-p[c], c-1);
 
}
 
int main(){
 
    int top = 1;

    ll n;
    scanf("%lld", &n);
 
    for(int i=2;;i++){
        p[i] = p[i-1] + p[i-2];
        top = i;
        if(p[i] >= n)break;
    }

    printf("%d\n", top);
 
    // fibonacci number start, lose
 
    ll flg = func(n, top);
 
    if(flg == n)flg = -1;
    printf("%lld\n", flg);
 
}
