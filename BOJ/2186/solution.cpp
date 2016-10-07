#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char str[103][103];
char tar[83];

int dp[103][103][83];

int n, m, k, s;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int dy(int r, int c, int v){

    if(v == s-1)return 1;

    int &ret = dp[r][c][v];

    if(ret != -1)return ret;

    ret = 0;

    for(int dk=1; dk<=k; dk++){
        for(int i=0; i<4; i++){
            int nr = r + dk*dr[i], nc = c + dk*dc[i], nv = v+1;
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
            if(str[nr][nc] == tar[nv]){
                ret += dy(nr, nc, nv);
            }
        }
    }

    return ret;

}

int main(){

    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
    }

    scanf("%s", tar);

    s = strlen(tar);

    int ans = 0;

    for(int i=0; i<n; i++)for(int j=0; j<m; j++)for(int a=0; a<s; a++)dp[i][j][a] = -1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(str[i][j] == tar[0]){
                ans += dy(i, j, 0);
            }
        }
    }

    printf("%d\n", ans);

}
