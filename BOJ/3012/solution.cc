// BOJ 3012

#include <cstdio>
#include <cstring>

using namespace std;

using ll = long long;

bool flag = false;

const ll lmod = 100000;
ll dp[203][203];

int n;
char str[203];

char left[] = "({[";
char right[] = ")}]";

ll dy(int l, int r){

    if(l > r)return 1;

    ll &ret = dp[l][r];

    if(ret != -1)return ret;

    ret = 0;

    for(int i=l+1; i<=r; i+=2){
        for(int j=0; j<3; j++){
            if(str[l] == left[j] || str[l] == '?'){
                if(str[i] == right[j] || str[i] == '?'){
                    ll v = (dy(l+1, i-1) * dy(i+1, r));
                    if(v >= lmod)v = lmod + (v % lmod);
                    ret += v;
                }
            }
        }
    }

    return ret;

}

int main(){

    scanf("%d %s", &n, str);

    if(n&1){
        printf("0\n");
        return 0;
    }

    for(int i=0; i<n; i++)for(int j=i; j<n; j++)dp[i][j] = -1;

    if(dy(0, n-1) < lmod)printf("%lld\n", dy(0, n-1));
    else
        printf("%05lld\n", dy(0, n-1) % lmod);

}
