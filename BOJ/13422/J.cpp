#include <cstdio>

using namespace std;

int e[200003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i=1; i<=n; i++){
            scanf("%d", &e[i]);
        }

        for(int i=n+1; i<=n+m-1; i++){
            e[i] = e[i-n];
        }

        for(int i=1; i<=n+m-1; i++)e[i] += e[i-1];

        int ans = 0;

        for(int i=m; i<=n+m-1; i++){
            ans += (e[i] - e[i-m]) < k;
        }

        if(ans && n == m)ans = 1;

        printf("%d\n", ans);

    }

}
