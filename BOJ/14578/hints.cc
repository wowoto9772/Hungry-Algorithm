#include <cstdio>

using namespace std;

int row[13];
int col[13];

int e[13][13];
int ans, n;

void dfs(int i, int j){
    if(i == n+1){
        bool flag = false;
        for(int i=1; i<=n && !flag; i++){
            if(row[i] != 3 || col[i] != 3)flag = true;
        }
        ans += ((flag) ? 0 : 1);
        return ;
    }else if(j == n+1){
        dfs(i+1, 1);
        return ;
    }else if(col[j] == 3 || row[i] == 3){
        dfs(i, j+1);
        return ;
    }
    for(int k=0; k<2; k++){
        if(row[i] & (1<<k))continue;
        if(col[j] & (1<<k))continue;
        row[i] ^= (1<<k);
        col[j] ^= (1<<k);
        dfs(i, j+1);
        row[i] ^= (1<<k);
        col[j] ^= (1<<k);
    }
    dfs(i, j+1);
}

int main(){

    scanf("%d", &n);

    dfs(1, 1);

    printf("%d\n", ans);

}
