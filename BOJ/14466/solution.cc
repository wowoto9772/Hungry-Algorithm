#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set < pair<int,int> > cant[103][103];
pair <int,int> my[103];

bool chk[103][103];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int n;

void dfs(int x, int y){
    if(chk[x][y])return ;
    chk[x][y] = true;
    for(int i=0; i<4; i++){
        int a = x + dr[i], b = y + dc[i];
        if(a < 1 || b < 1 || a > n || b > n)continue;
        pair<int,int> v = make_pair(a,b);
        set < pair<int,int> >::iterator p = cant[x][y].lower_bound(v);
        if(p != cant[x][y].end() && *p == v)continue;
        dfs(a, b);
    }
}

int main(){
    
    int k, r;
    scanf("%d %d %d", &n, &k, &r);
    
    for(int i=0; i<r; i++){
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        cant[x][y].emplace(a,b);
        cant[a][b].emplace(x,y);
    }
    
    int ans = 0;
    
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        
        for(int a=1; a<=n; a++)for(int b=1; b<=n; b++)chk[a][b] = false;
        my[i] = {x, y};
        dfs(x, y);
        for(int j=0; j<i; j++){
            if(!chk[my[j].first][my[j].second])ans++;
        }
    }
    
    printf("%d\n", ans);

}