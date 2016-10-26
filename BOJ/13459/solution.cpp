#include <cstdio>
#include <queue>

using namespace std;

class pts{
    public:
        int r, c;
        pts(){}
        pts(int _r, int _c){
            r = _r, c = _c;
        }
};

class ele{
    public:
        pts red, blue;
        int c;
        ele(){}
        ele(pts _r, pts _b, int _c){
            red = _r, blue = _b, c = _c;
        }
};

int dr [] = {0, 0, -1, 1};
int dc [] = {-1, 1, 0, 0};
bool chk[13][13][13][13];

char str[13][13];

int main(){

    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; i++)scanf("%s", str[i]);

    pts red, blue;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(str[i][j] == 'R')red = {i,j};
            else if(str[i][j] == 'B')blue = {i,j};
        }
    }

    queue <ele> q;
    q.emplace(red, blue, 0);
    chk[red.r][red.c][blue.r][blue.c] = true;

    while(!q.empty()){
        ele f = q.front(); q.pop();
        //        printf("%d %d %d %d %d\n", f.blue.r, f.blue.c, f.red.r, f.red.c, f.c);
        if(f.c < 10){
            for(int k=0; k<4; k++){
                red = f.red, blue = f.blue;
                bool suc = false, inv = false;
                while(!inv){
                    int flg = 0;
                    if(red.r + dr[k] == blue.r && red.c + dc[k] == blue.c){
                        blue.r += dr[k];
                        blue.c += dc[k];
                        if(str[blue.r][blue.c] == 'O'){
                            inv = true;
                        }else if(str[blue.r][blue.c] == '#'){
                            blue.r -= dr[k];
                            blue.c -= dc[k];
                            flg++;
                        }
                        red.r += dr[k];
                        red.c += dc[k];
                        if(str[red.r][red.c] == 'O'){
                            suc = true;
                        }else if(str[red.r][red.c] == '#' || blue.r == red.r && blue.c == red.c){
                            red.r -= dr[k];
                            red.c -= dc[k];
                            flg++;
                        }
                    }else{
                        red.r += dr[k];
                        red.c += dc[k];
                        if(str[red.r][red.c] == '#'){
                            red.r -= dr[k];
                            red.c -= dc[k];
                            flg++;
                        }else if(str[red.r][red.c] == 'O'){
                            suc = true;
                        }
                        blue.r += dr[k];
                        blue.c += dc[k];
                        if(str[blue.r][blue.c] == 'O'){
                            inv = true;
                        }else if(str[blue.r][blue.c] == '#' || blue.r == red.r && blue.c == red.c){
                            blue.r -= dr[k];
                            blue.c -= dc[k];
                            flg++;
                        }
                    }
                    if(flg == 2)break;
                }
                if(inv)continue;
                if(suc){
                    printf("1\n");
                    return 0;
                }
                if(chk[red.r][red.c][blue.r][blue.c])continue;
                chk[red.r][red.c][blue.r][blue.c] = true;
                q.emplace(red, blue, f.c+1);
            }
        }

    }

    printf("0\n");

}
