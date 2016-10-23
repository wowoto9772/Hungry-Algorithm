#include <cstdio>
#include <limits.h>
#include <cstring>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[103][103][103];
char str[103], tar[103];
int n;

int dy(int c, int o, int z){

    if(c == n){
        if(o > z)return INT_MAX>>2;
        else{
            int d = min(o, z);
            o -= d;
            z -= d;
            return d + z;
        }
    }

    int &ret = dp[c][o][z];

    if(ret != -1)return ret;

    if(str[c] == tar[c]){
        ret = dy(c+1, o, z);
    }else{
        if(str[c] == '?'){
            ret = 1 + dy(c+1, o, z);
            if(tar[c] == '1')ret = min(ret, 1 + dy(c+1, o, z+1));
            else
                ret = min(ret, 1 + dy(c+1, o+1, z));
        }else{
            if(str[c] == '1')ret = dy(c+1, o+1, z);
            else
                ret = dy(c+1, o, z+1);
        }
    }

    return ret;

}

int main(){

    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){

        memset(dp, 0xff, sizeof(dp));

        scanf("%s %s", str, tar);

        printf("Case %d: ", ++tc);

        n = strlen(str);

        int flg = dy(0, 0, 0);

        if(flg >= (INT_MAX>>2))flg = -1;

        printf("%d\n", flg);

    }

}
