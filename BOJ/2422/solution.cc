#include <cstdio>

using namespace std;

bool dont[203][203];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        dont[a][b] = dont[b][a] = true;
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(dont[i][j])continue;
            for(int k=j+1; k<=n; k++){
                if(dont[i][k] || dont[j][k])continue;
                ans++;
            }
        }
    }

    printf("%d\n", ans);

}
