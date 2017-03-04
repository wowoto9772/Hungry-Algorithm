#include <cstdio>
#include <algorithm>

using namespace std;

int e[303][303];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &e[i][j]);
            e[i][j] += max(e[i-1][j], e[i][j-1]);
        }
    }

    printf("%d\n", e[n][m]);

}
