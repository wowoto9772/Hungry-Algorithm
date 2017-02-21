#include <cstdio>
#include <cstring>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

char str[1003][1003];
int d[1003][1003][13];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

class ele{
    public:
        int r, c, m, k;
        ele(){}
        ele(int _r, int _c, int _m, int _k){
            r = _r, c = _c, m = _m, k = _k;
        }

        bool operator<(const ele &A)const{
            return m > A.m;
        }
};

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++)scanf("%s", str[i]);

    priority_queue < ele > q;

    q.emplace(0, 0, 1, 0);
    memset(d, 0x4f, sizeof(d));
    d[0][0][0] = 1;

    int ans = -1;

    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(f.r == n-1 && f.c == m-1){
            if(ans == -1)ans = f.m;
            else if(ans > f.m)ans = f.m;
            continue;
        }
        for(int i=0; i<4; i++){
            ele g = {f.r+dr[i], f.c+dc[i], f.m+1, f.k};
            if(g.r < 0 || g.r >= n || g.c < 0 || g.c >= m)continue;
            if(str[g.r][g.c] == '1')g.k++;
            if(g.k > k)continue;
            if(d[g.r][g.c][g.k] > g.m){
                d[g.r][g.c][g.k] = g.m;
                q.emplace(g);
            }
        }
    }

    printf("%d\n", ans);

}
