#include <cstdio>
#include <algorithm>

using namespace std;

int e[23];

int main(){

    int n, s;
    scanf("%d %d", &n, &s);

    for(int i=0; i<n; i++)scanf("%d", &e[i]);

    int ans = s;

    for(int i=1; i<(1<<n); i++){
        int v = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j))v += e[j];
        }
        if(v >= s)ans = min(ans, v-s);
    }

    printf("%d\n", ans);

}
