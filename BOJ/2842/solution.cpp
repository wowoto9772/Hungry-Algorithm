#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define x first
#define y second

char str[53][53];
int h[53][53];

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int main(){

    int n;
    scanf("%d", &n);

    pair <int,int> s;

    int tot = 0;

    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
        for(int j=0; j<n; j++){
            if(str[i][j] == 'P'){
                s = {i, j};
            }else if(str[i][j] == 'K'){
                tot++;
            }
        }
    }

    set <int> lo;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &h[i][j]);
            lo.insert(h[i][j]);
        }
    }

    int l = 0, r = 1000000, m;

    int ans = 1000000;

    while(l <= r){

        m = (l+r) >> 1;

        bool pos = false;

        for(auto &mini : lo){

            queue < pair<int,int> > q;
            
            int maxi = mini + m;

            if(mini <= h[s.x][s.y] && h[s.x][s.y] <= maxi){

                vector < vector <bool> > chk;
                chk.resize(n);
                for(int j=0; j<n; j++)chk[j].resize(n, false);

                chk[s.x][s.y] = true;
                q.emplace(s);

                int cur = 0;

                while(!q.empty()){

                    pair <int,int> f = q.front(); q.pop();

                    for(int i=0; i<8; i++){

                        pair <int,int> g = {f.x + dx[i], f.y + dy[i]};

                        if(g.x < 0 || g.x >= n || g.y < 0 || g.y >= n)continue;

                        if(chk[g.x][g.y])continue;

                        if(mini <= h[g.x][g.y] && h[g.x][g.y] <= maxi){

                            if(str[g.x][g.y] == 'K'){
                                cur++;
                            }

                            chk[g.x][g.y] = true;
                            q.emplace(g);

                        }

                    }

                }

                if(cur == tot){
                    pos = true;
                    break;
                }

            }

        }

        if(pos){
            r = m - 1;
            ans = min(ans, m);
        }
        else{
            l = m + 1;
        }

    }

    printf("%d\n", ans);

}
