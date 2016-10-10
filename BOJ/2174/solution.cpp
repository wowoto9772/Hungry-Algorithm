#include <cstdio>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int x[103], y[103], d[103];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    int n, m;
    scanf("%d %d", &n, &m);

    int map[103][103] = {};

    for(int i=1; i<=n; i++){
        scanf(" %d %d %c", &x[i], &y[i], &d[i]);
        map[x[i]][y[i]] = i;

        if(d[i] == 'E')d[i] = 0;
        else if(d[i] == 'S')d[i] = 1;
        else if(d[i] == 'W')d[i] = 2;
        else
            d[i] = 3;
    }

    bool flag = false;

    for(int i=1; i<=m; i++){
        int id;
        char cmd;
        int cnt;
        scanf(" %d %c %d", &id, &cmd, &cnt);

        if(flag)continue;

        if(cmd == 'R'){
            cnt %= 4;
            d[id] += cnt;
            d[id] %= 4;
        }else if(cmd == 'L'){
            cnt %= 4;
            d[id] -= cnt;
            d[id] += 4;
            d[id] %= 4;
        }else{
            int px = x[id], py = y[id];
            int cx = px, cy = py;
            for(int j=1; j<=cnt && !flag; j++){
                cx += dx[d[id]];
                cy += dy[d[id]];
                if(cx < 1 || cy < 1 || cx > r || cy > c){
                    printf("Robot %d crashes into the wall\n", id);
                    flag = true;
                }else if(map[cx][cy]){
                    printf("Robot %d crashes into robot %d\n", id, map[cx][cy]);
                    flag = true;
                }
            }

            if(!flag){
                map[px][py] = 0, map[cx][cy] = id;
                x[id] = cx, y[id] = cy;
            }

        }
    }

    if(!flag)printf("OK\n");


}
