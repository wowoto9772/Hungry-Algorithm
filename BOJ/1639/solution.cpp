#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[103];
int d[103];

int main(){

    scanf("%s", str+1);

    int s = strlen(str+1);

    for(int i=1; i<=s; i++){
        d[i] = d[i-1] + str[i] - '0';
    }

    int ans = 0;

    for(int m=1; m<=s/2; m++){

        int c = 0;
        bool p = false;
        for(int i=m; i<=s-m && !p; i++){
            if(d[i] - d[i-m] == d[i+m] - d[i]){
                p = true;
            }
        }

        if(p){
            ans = max(ans, m);
        }

    }

    printf("%d\n", ans<<1);

}
