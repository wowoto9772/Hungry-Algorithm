#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct LINE{
    int x[2], y[2];
    double m, yi;

    void calc(){
        if(x[0] == x[1])m = 0;
        else
            m = (y[1]-y[0])/(double)(x[1]-x[0]);
        yi = y[0] - m * x[0];
    }

    double Y(int _x){
        return m * _x + yi;
    }
}seg[5003];

bool outFirst(int i, int j){
    int rx = min(seg[i].x[1], seg[j].x[1]);
    int lx = max(seg[i].x[0], seg[j].x[0]);

    if(lx <= rx){
        if(seg[i].Y(rx) < seg[j].Y(rx)){
            return true;
        }
    }

    return false;
}

int in[5003];
bool nxt[5003][5003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=0; j<2; j++){
            scanf("%d %d", &seg[i].x[j], &seg[i].y[j]);
        }
        if(seg[i].x[0] > seg[i].x[1]){
            swap(seg[i].x[0], seg[i].x[1]);
            swap(seg[i].y[0], seg[i].y[1]);
        }else if(seg[i].x[0] == seg[i].x[1]){
            if(seg[i].y[0] > seg[i].y[1]){
                swap(seg[i].y[0], seg[i].y[1]);
            }
        }
        seg[i].calc();
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)continue;
            if(outFirst(i, j)){
                in[j]++;
                nxt[i][j] = true;
            }
        }
    }

    queue <int> q;
    for(int i=1; i<=n; i++){
        if(in[i] == 0)q.push(i);
    }

    while(!q.empty()){
        int f = q.front();q.pop();
        printf("%d ", f);
        for(int i=1; i<=n; i++){
            if(f == i)continue;
            if(nxt[f][i]){
                if(--in[i] == 0){
                    q.push(i);
                }
            }
        }
    }

}
