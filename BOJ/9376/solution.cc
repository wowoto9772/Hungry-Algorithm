#include <cstdio>
#include <queue>

const int MAX_INT = (1<<31)-1;

using namespace std;
class ele{
    public:
    int r, c, m;
    ele(){}
    ele(int _r, int _c){
        r = _r, c = _c, m = 0;
    }
    ele(int _r, int _c, int _m){
        r = _r, c = _c, m = _m;
    }
   
    bool operator<(const ele &A)const{
        return m > A.m;
    }
};

char str[107][107];
int d[3][107][107];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){
    
    int t;
    scanf("%d", &t);
    
    while(t--){
        int r, c;
        scanf("%d %d", &r, &c);
        r+=2, c+=2;
        ele e[3];
        e[0] = {0, 0};
        e[1] = e[2] = {-1, 0};
        for(int i=0; i<r; i++)for(int j=0; j<c; j++){
            str[i][j] = 0;
            for(int k=0; k<3; k++){
                d[k][i][j] = MAX_INT;
            }
        }
        for(int i=1; i<r-1; i++){
            scanf("%s", str[i]+1);
            for(int j=1; j<c-1; j++){
                if(str[i][j] == '$'){
                    if(e[1].r == -1){
                        e[1] = {i, j};
                    }else{
                        e[2] = {i, j};
                    }
                }
            }
        }
        
        for(int i=0; i<3; i++){
            priority_queue < ele > q;
            q.emplace(e[i]);
            d[i][e[i].r][e[i].c] = 0;
            while(!q.empty()){
                ele f = q.top(); q.pop();
                if(d[i][f.r][f.c] < f.m)continue;
                for(int j=0; j<4; j++){
                    ele g = {f.r + dr[j], f.c + dc[j], f.m};
                    if(g.r < 0 || g.r >= r || g.c < 0 || g.c >= c)continue;
                    if(str[g.r][g.c] == '*')continue;
                    else if(str[g.r][g.c] == '#')g.m++;
                    if(d[i][g.r][g.c] > g.m){
                        d[i][g.r][g.c] = g.m;
                        q.emplace(g);
                    }
                }
            }
        }
        
        int ans = MAX_INT;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(d[0][i][j] == MAX_INT || d[1][i][j] == MAX_INT || d[2][i][j] == MAX_INT)continue;
                int k = d[0][i][j] + d[1][i][j] + d[2][i][j];
                if(str[i][j] == '#')k -= 2;
                if(ans > k)ans = k;
            }
        }    
        
        printf("%d\n", ans);
    }

}