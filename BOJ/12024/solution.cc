#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
ll e[253][253], f[253][253];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%lld", &e[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(i == k || k == j || i == j)continue;
                f[i][j] += e[i][k] * e[k][j];
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)continue;
            ans += f[i][j] * (f[i][j]-1);
        }
    }

    printf("%lld\n", ans);

}
