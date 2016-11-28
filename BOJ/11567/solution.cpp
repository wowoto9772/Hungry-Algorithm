#include <cstdio>
#include <queue>

using namespace std;

bool chk[503][503];
char str[503][503];
int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++){
        scanf("%s", str[i]);
        for(int j=0; j<c; j++){
            if(str[i][j] == 'X')chk[i][j] = true;
        }
    }

    int sx, sy;
    scanf("%d %d", &sx, &sy);
    sx--, sy--;
    queue < pair<int,int> > q;
    q.emplace(sx, sy);
    scanf("%d %d", &sx, &sy);
    sx--, sy--;

    while(!q.empty()){
        pair <int,int> f = q.front(); q.pop();
        for(int i=0; i<4; i++){
            pair <int,int> g = {f.first+dr[i], f.second+dc[i]};
            if(g.first < 0 || g.first >= r || g.second < 0 || g.second >= c)continue;
            if(chk[g.first][g.second]){
                if(g.first == sx && g.second == sy){
                    printf("YES\n");
                    return 0;
                }
            }else{
                chk[g.first][g.second] = true;
                q.emplace(g);
            }
        }
    }

    printf("NO\n");

}
