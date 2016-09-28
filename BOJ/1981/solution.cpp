#include <cstdio>

#include <queue>

#include <algorithm>

using namespace std;

int d[103][103], e[103][103];

int main(){

    int n;
    scanf("%d", &n);

    int mini = 201, maxi = -1;

    for(int i=1; i<=n; i++){

        for(int j=1; j<=n; j++){

            scanf("%d", &e[i][j]);

            mini = min(mini, e[i][j]);
            maxi = max(maxi, e[i][j]);

        }

    }

    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};

    int top = 0;

    int gap = 203;

    for(int i=mini; i<=maxi; i++){

        for(int j=i; j<=maxi && j <= i + gap; j++){

            if(i <= e[1][1] && e[1][1] <= j){

                if(i <= e[n][n] && e[n][n] <= j ){

                    queue < pair<int,int> > q;

                    d[1][1] = ++top;
                    q.emplace(1, 1);

                    while(!q.empty() && d[n][n] != top){

                        pair<int,int> f = q.front(); q.pop();

                        for(int k=0; k<4; k++){

                            pair<int,int> g = {f.first + dr[k], f.second + dc[k]};

                            if(g.first < 1 || g.first > n || g.second < 1 || g.second > n)continue;

                            if(d[g.first][g.second] == top)continue;

                            int v = e[g.first][g.second];

                            if(i <= v && v <= j){

                                d[g.first][g.second] = top;
                                q.emplace(g);

                            }

                        }

                    }

                    if(d[n][n] == top){
                        gap = min(gap, j-i);
                    }

                }

            }

        }

    }

    printf("%d\n", gap);

}
