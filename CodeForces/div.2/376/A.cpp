#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[103];

int main(){
  
    scanf("%s", str);

    int s = strlen(str);

    int ans = 0;

    int p = 'a';

    for(int i=0; i<s; i++){

        int d = str[i] - p;

        if(d < 0)d += 26;

        int e = p - str[i];

        if(e < 0)e += 26;

        ans += min(d, e);

        p = str[i];

    }

    printf("%d\n", ans);

    return 0;

}
