#include <cstdio>
#include <queue>

using namespace std;

char str[103][103];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int r, c;
        scanf("%d %d", &r, &c);
        for(int i=0; i<r; i++)scanf("%s", str[i]);
       
        bool chk[103][103] = {};
        queue < pair <int,int> > q;
        
        int ans = 0;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(chk[i][j])continue;
                if(str[i][j] == '#'){
                    ans++;
                    q.emplace(i, j);
                    while(!q.empty()){
                        pair <int,int> f = q.front(); q.pop();
                        for(int k=0; k<4; k++){
                            pair <int,int> g = {f.first + dr[k], f.second + dc[k]};
                            if(g.first < 0 || g.first >= r || g.second < 0 || g.second >= c)continue;
                            if(chk[g.first][g.second])continue;
                            if(str[g.first][g.second] == '#'){
                                q.emplace(g);
                                chk[g.first][g.second] = true;
                            }
                        }
                    }
                }
            }
        }
        
        printf("%d\n", ans);
    }

}