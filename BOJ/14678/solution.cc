#include <cstdio>
#include <vector>

using namespace std;

vector < vector < int > > lnk;
vector < int > c, color;

int cnt[2];

void dfs(int u, int r){
    if(color[u] != -1)return ;
    color[u] = r;
    
    if(c[u] == 1){
        cnt[r&1]++;
    }
    
    for(auto &v : lnk[u]){
        dfs(v, 1^r);
    }
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    if(n == 1){
        printf("1\n");
        return 0;
    }
    
    lnk.resize(n+1), c.resize(n+1), color.resize(n+1, -1);
    
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        lnk[a].push_back(b);
        lnk[b].push_back(a);
        c[a]++, c[b]++;
    }
    
    dfs(1, 0);
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        int tmp = cnt[color[i]] - (c[i] == 1);
        if(ans < tmp)ans = tmp;
    }
    
    printf("%d\n", ans);

}