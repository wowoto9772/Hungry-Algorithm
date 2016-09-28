#include <cstdio>

#include <vector>

using namespace std;

using ll = long long;

ll d[100003];
ll dp[100003];

int n;

ll dy(int i){

    if(i >= n)return 0LL;

    ll &ret = dp[i];

    if(ret != -1)return ret;

    ret = max(d[i] + dy(i+2), dy(i+1));

    return ret;

}

int main(){

    int m;
    while(scanf("%d %d", &n, &m) == 2){

        if(!(n|m))break;

        for(int i=0; i<n; i++){
            
            d[i] = 0;
            
            vector <int> e(m+1, 0);
            
            for(int j=1; j<=m; j++){
            
                int v;
                scanf("%d", &v);

                e[j] = v;

                if(j >= 3)e[j] = max(e[j], e[j-3] + v);

                if(j >= 2)e[j] = max(e[j], e[j-2] + v);
                
                e[j] = max(e[j], e[j-1]);

            }

            d[i] = e[m];

            dp[i] = -1;
        }

        printf("%lld\n", dy(0));

    }

}
