#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int L[1003], R[1003];

int main(){

    int n, T;
    scanf("%d %d", &n, &T);

    for(int i=1; i<=n; i++){
        scanf("%d %d", &L[i], &R[i]);
    }

    int ans = INT_MAX;
    int l = 0, r = 1000000, m;
    while(l <= r){
        m = (l+r) >> 1;
        int cl = 0;
        int cr = 0;
        bool imp = false;
        for(int i=1; i<=n; i++){
            if(m < L[i])imp = true;
            cr += min(m, R[i]);
            cl += L[i];
        }
        if(!imp && cl <= T && T <= cr){
            ans = m;
            r = m - 1;
        }else
            l = m + 1;
    }

    if(ans == INT_MAX)ans = -1;
    printf("%d\n", ans);

}
