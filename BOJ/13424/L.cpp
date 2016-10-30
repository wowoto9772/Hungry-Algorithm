#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int e[103];
int c[103][103];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)c[i][j] = INT_MAX;
            c[i][i] = 0;
        }

        int m;
        scanf("%d", &m);

        while(m--){
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            if(c[a][b] > d)c[a][b] = c[b][a] = d;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                if(c[i][k] == INT_MAX)continue;
                for(int j=1; j<=n; j++){
                    if(c[k][j] == INT_MAX)continue;
                    c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
                }
            }
        }

        int k;
        scanf("%d", &k);

        for(int i=1; i<=k; i++){
            scanf("%d", &e[i]);
        }

        int ans = INT_MAX, x;

        for(int i=1; i<=n; i++){
            int tmp = 0;
            for(int j=1; j<=k; j++){
                tmp += c[i][e[j]];
            }
            if(ans > tmp){
                ans = tmp;
                x = i;
            }
        }printf("%d\n", x);

    }

}
