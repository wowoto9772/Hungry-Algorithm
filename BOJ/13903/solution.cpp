#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

bool chk[1003][1003];
int e[1003][1003];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    queue < tuple<int,int,int> > q;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            scanf("%d", &e[i][j]);
            if(i == 1 && e[i][j]){
                q.emplace(i, j, 0);
                chk[i][j] = true;
            }
        }
    }

    int n;
    scanf("%d", &n);

    vector <int> dr(n), dc(n);

    for(int i=0; i<n; i++)scanf("%d %d", &dr[i], &dc[i]);

    while(!q.empty()){
        tuple<int,int,int> f = q.front(); q.pop();
        if(get<0>(f) == r){
            printf("%d\n", get<2>(f));
            return 0;
        }
        for(int i=0; i<n; i++){
            int x = get<0>(f)+dr[i], y = get<1>(f)+dc[i], z = get<2>(f)+1;
            if(x < 1 || x > r || y < 1 || y > c)continue;
            if(!e[x][y])continue;
            if(chk[x][y])continue;
            chk[x][y] = true;
            q.emplace(x,y,z);
        }
    }
    printf("-1\n");
    return 0;

}
