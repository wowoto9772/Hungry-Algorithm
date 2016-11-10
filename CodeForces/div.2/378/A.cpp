#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[103];
int e[103];

int main(){

    e['A'] = e['E'] = e['I'] = e['O'] = e['U'] = e['Y'] = 1;

    scanf("%s", str+1);

    int s = strlen(str+1);

    int p = 0;

    int ans = 0;

    for(int i=1; i<=s; i++){
        if(e[str[i]]){
            ans = max(ans, i-p);
            p = i;
        }
    }

    ans = max(ans, s+1 - p);

    printf("%d\n", ans);

}
