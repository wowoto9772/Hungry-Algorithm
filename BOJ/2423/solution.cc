#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

class ele{
    public:
        int r, c, m;
        bool d;
        ele(){}
        ele(int _r, int _c, int _m, bool _d){
            r = _r, c = _c, m = _m, d = _d;
        }

        bool operator<(const ele &A)const{
            return m > A.m;
        }
};

char str[503][503];
int dr[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dc[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int chk[503][503][2];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)scanf("%s", str[i]);

    memset(chk, 0x4f, sizeof(chk));

    priority_queue <ele> q;

    if(str[0][0] == '\\'){
        chk[0][0][0] = true;
        q.emplace(0, 0, 0, false);
    }else{
        chk[0][0][1] = true;
        q.emplace(0, 0, 1, true);
    }

    while(!q.empty()){
        ele f = q.top(); q.pop();
        if(chk[f.r][f.c][f.d] < f.m)continue;
        char cur = str[f.r][f.c];
        if(f.d)cur = ((str[f.r][f.c] == '\\') ? '/' : '\\');
        if(f.r == n-1 && f.c == m-1 && cur == '\\'){
            printf("%d\n", f.m);
            return 0;
        }
        for(int i=0; i<8; i++){
            ele g = {f.r+dr[i], f.c+dc[i], f.m, false};
            if(g.r < 0 || g.r >= n || g.c < 0 || g.c >= m)continue;
            if(i <= 3){
                if(cur == str[g.r][g.c])g.d = true, g.m++;
            }else{
                if(cur == '\\'){
                    if(i >= 6)continue;
                    if(str[g.r][g.c] != '\\')g.d = true, g.m++;
                }else{
                    if(i < 6)continue;
                    if(str[g.r][g.c] != '/')g.d = true, g.m++;
                }
            }
            if(chk[g.r][g.c][g.d] > g.m){
                chk[g.r][g.c][g.d] = g.m;
                q.emplace(g);
            }
        }
    }

    printf("NO SOLUTION\n");

}
