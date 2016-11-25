#include <cstdio>
#include <memory.h>

using namespace std;

int dp[103][103][2];

int dy(int a, int b, int p){
    if(a == 1 && b == 1){
        return !p;
    }else{
        int &ret = dp[a][b][p];
        if(ret != -1)return ret;
        ret = !p;
        if(b >= 2){
            for(int nb=1; nb<b; nb++){
                int na = b - nb;
                ret = dy(na, nb, !p);
                if(ret == p)return ret;
            }
        }
        if(a >= 2){
            for(int na=1; na<a; na++){
                int nb = a - na;
                ret = dy(na, nb, !p);
                if(ret == p)return ret;
            }
        }
        return ret;
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    memset(dp, 0xff, sizeof(dp));

    if(dy(n,m,0) == 0)printf("A\n");
    else
        printf("B\n");

}
