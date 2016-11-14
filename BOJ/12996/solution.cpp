#include <cstdio>
#include <memory.h>

using ll = long long;
using namespace std;
const ll lmod = 1000000007LL;

ll dp[53][53][53][53];

ll dy(int s, int a, int b, int c){
    if(s == 0){
        return a == 0 && b == 0 && c == 0;
    }
    ll &ret = dp[s][a][b][c];
    if(ret != -1)return ret;
    ret = 0;
    if(a){
        ret += dy(s-1, a-1, b, c);
        if(b){
            ret += dy(s-1, a-1, b-1, c);
            if(c)ret += dy(s-1, a-1, b-1, c-1);
        }
        if(c){
            ret += dy(s-1, a-1, b, c-1);
        }
    }
    if(b){
        ret += dy(s-1, a, b-1, c);
        if(c){
            ret += dy(s-1, a, b-1, c-1);
        }
    }
    if(c)ret += dy(s-1, a, b, c-1);
    return ret %= lmod;
}

int main(){

    int s, e[3];
    scanf("%d", &s);

    for(int i=0; i<3; i++)scanf("%d", &e[i]);

    memset(dp, 0xff, sizeof(dp));
    printf("%lld\n", dy(s, e[0], e[1], e[2]));

}
