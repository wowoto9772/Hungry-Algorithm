#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

ll c[10];

void calc(int v, int t){
    while(v){
        c[v%10] += t;
        v /= 10;
    }
}

void proc(int s, int e, int t){
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
    for(int i=0; i<10; i++)c[i] += cnt*t;
    proc(s/10, e/10, t*10);
}

int main(){

    int s = 1, e;
    scanf("%d", &e);

    proc(s, e, 1);

    for(int i=0; i<10; i++)printf("%lld ", c[i]);

}
