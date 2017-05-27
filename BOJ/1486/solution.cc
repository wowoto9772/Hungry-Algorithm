#include <cstdio>
#include <limits.h>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

class ele{
    public:
        int a, b, c;
        ele(){}
        ele(int _a, int _b, int _c){
            a = _a, b = _b, c = _c;
        }
}E[4000];

int Cv['z' + 3];
int di[4] = { 0, 0, -1, 1 };
int dj[4] = { -1, 1, 0, 0 };

int main(){

    int x = 0;
    for (int i = 'A'; i <= 'Z'; i++)Cv[i] = x++;
    for (int i = 'a'; i <= 'z'; i++)Cv[i] = x++;

    int R, C, K, D;
    scanf("%d %d %d %d", &R, &C, &K, &D);

    int top = 0;

    char str[32][32] = { 0 };

    for (int i = 0; i < R; i++)scanf("%s", str[i]);

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            int now = i * C + j, nxt, h;
            for (int k = 0; k < 4; k++){
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < R && nj >= 0 && nj < C){
                    h = abs(Cv[str[i][j]] - Cv[str[ni][nj]]);
                    if (h <= K){
                        nxt = ni * C + nj;
                        if (str[i][j] >= str[ni][nj]){
                            E[top].a = now, E[top].b = nxt, E[top].c = 1;
                            top++;
                        }
                        else{
                            E[top].a = now, E[top].b = nxt, E[top].c = h*h;
                            top++;
                        }
                    }
                }
            }
        }
    }

    ll d[800];
    for(int i=0; i<R*C; i++)d[i] = INT_MAX;

    d[0] = 0;
    bool update = false;

    for (int i = 1; i <= R*C; i++){
        for (int j = 0; j < top; j++){
            if (d[E[j].b] > d[E[j].a] + E[j].c){
                d[E[j].b] = d[E[j].a] + E[j].c;
                update = true;
            }
        }
        if (!update)break;
    }

    int ans = Cv[str[0][0]];

    for (int i = 1; i < R*C; i++){
        if (d[i] < D && ans < Cv[str[i/C][i%C]]){
            ll d2[800];
            for(int j=0; j<R*C; j++)d2[j] = INT_MAX;

            d2[i] = 0;
            update = false;

            for (int j = 1; j <= R*C; j++){
                for (int j = 0; j < top; j++){
                    if (d2[E[j].b] > d2[E[j].a] + E[j].c){
                        d2[E[j].b] = d2[E[j].a] + E[j].c;
                        update = true;
                    }
                }
                if (!update)break;
            }

            if (d[i] + d2[0] <= D){
                ans = max(ans, Cv[str[i/C][i%C]]);
            }
        }
    }

    printf("%d\n", ans);

}
