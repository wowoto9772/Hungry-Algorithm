#include <cstdio>
#include <algorithm>

using namespace std;

int a[1003], b[1003];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=k; i++){
        scanf("%d %d", &a[i], &b[i]);
        if(a[i] > b[i])swap(a[i], b[i]);
    }

    int ans = 0, cur = 0;

    while(cur <= n){

        int nxt = n;

        for(int i=1; i<=k; i++){
            if(cur <= a[i] && b[i] <= nxt){
                nxt = b[i] - 1;
            }
        }

        ans++;
        cur = nxt + 1;

    }

    printf("%d\n", ans);

}
