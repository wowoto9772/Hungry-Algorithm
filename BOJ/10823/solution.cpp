#include <cstdio>
#include <cstring>

using ll = long long;
using namespace std;

char str[10003], tmp[10003];

int main(){

    while(scanf("%s", tmp) == 1){
        strcat(str, tmp);
    }

    long long ans = 0;

    char *p = strtok(str, ",");
    sscanf(p, "%lld", &ans);

    while(p = strtok(NULL, ",")){
        ll v;
        sscanf(p, "%lld", &v);
        ans += v;
    }

    printf("%lld\n", ans);

}
