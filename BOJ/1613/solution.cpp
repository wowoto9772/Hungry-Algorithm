#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int d[403][403];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = INT_MAX;
        }d[i][i] = 0;
    }

    for(int i=1; i<=m; i++){

        int a, b;
        scanf("%d %d", &a, &b);

        d[a][b] = 1;

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

        if(d[a][b] != INT_MAX)printf("-1\n");
        else if(d[b][a] != INT_MAX)printf("1\n");
        else
            printf("0\n");

    }

}
