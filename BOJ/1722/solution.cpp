#include <stdio.h>

using ll = long long;

ll fac[20] = {1};

int ans[23];

int main(){

    for(ll i=1; i<=19; i++)fac[i] = fac[i-1] * i;

    int n;
    scanf("%d", &n);

    int p;
    scanf("%d", &p);

    bool used[23] = {0};

    if(p == 1){

        ll k;
        scanf("%lld", &k);

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){

                if(used[j])continue;

                if(fac[n-i] < k){
                    k -= fac[n-i];
                }else{

                    used[j] = true;
                    printf("%d ", j);
                    break;

                }

            }

        }


    }else{

        ll ans = 0;

        for(int i=1; i<=n; i++){

            int e;
            scanf("%d", &e);

            for(int j=1; j<e; j++){

                if(used[j])continue;
                
                ans += fac[n-i];

            }

            used[e] = true;

        }

        printf("%lld\n", ++ans);

    }

}
