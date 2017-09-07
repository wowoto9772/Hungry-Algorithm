#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

vector < vector <int> > lnk;
ll x[33], y[33];
bool vst[33];
ll gap;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void dfs(int u, int S){
    for(int i=0; i<lnk[u].size(); i++){
        int v = lnk[u][i];
        if(vst[v])continue;
        
        int d;
        
        for(d=0; d<4; d++){
            if(S & (1<<d))continue;
            break;
        }
        
        S |= (1<<d);
        vst[v] = true;
        x[v] = x[u] + dr[d] * gap;
        y[v] = y[u] + dc[d] * gap;
        gap >>= 1;
        
        if(d <= 1){
            d++;
            d %= 2;
        }else{
            d++;
            if(d == 4)d -= 2;
        }
        
        dfs(v, (1<<d));
    }
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    lnk.resize(n+1);
    
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        if(lnk[i].size() > 4){
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    gap = (1LL<<55);
    vst[1] = true;
    x[1] = 1000000007, y[1] = 100007;
    dfs(1, 0);
    
    for(int i=1; i<=n; i++)printf("%lld %lld\n", x[i], y[i]);

}