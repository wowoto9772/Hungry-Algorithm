#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int d[253][253];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)d[i][j] = INT_MAX;
        d[i][i] = 0;
    }

    for(int i=1; i<=m; i++){
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);

        if(t)d[a][b] = d[b][a] = 0;
        else
            d[a][b] = 0, d[b][a] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(d[i][k] == INT_MAX)continue;
            for(int j=1; j<=n; j++){
                if(d[k][j] == INT_MAX)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int q;
    scanf("%d", &q);

    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", d[a][b]);
    }

}
