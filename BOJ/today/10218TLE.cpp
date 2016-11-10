#include <cstdio>
#include <queue>

using namespace std;

int dr [] = {0, 0, -1, 1};
int dc [] = {-1, 1, 0, 0};
char *out = "LRUD";
char str[13][13];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int r, c;
        scanf("%d %d", &r, &c);

        int sr, sc = -1;

        for(int i=0; i<r; i++){
            scanf("%s", str[i]);
            for(int j=0; j<c; j++){
                if(sc == -1 && str[i][j] == '.')sr = i, sc = j;
            }
        }

        bool ended = false;

        int limit = 1;

        vector < pair<int,int> > cand;

        for(int k=1; k<=10 && !ended; k++){
            limit <<= 2;
            for(int j=0; j<limit && !ended; j++){
                // 0, 1, 2, 3
                vector <int> cmd;
                int v = j;
                for(int i=1; i<=k; i++){
                    cmd.push_back(v&3);
                    v >>= 2;
                }
                int p = 0;
                int a = sr, b = sc;
                bool fin = false;
                while(p < cmd.size() && !fin){
                    a += dr[cmd[p]];
                    b += dc[cmd[p]];
                    if(str[a][b] == '#'){
                        a -= dr[cmd[p]];
                        b -= dc[cmd[p]];
                        p++;
                    }else if(str[a][b] == 'O'){
                        fin = true;
                    }
                }
                if(fin){
                    cand.emplace_back(j, k);
                }
            }
        }

        if(cand.empty())printf("XHAE\n");
        else{
            for(auto e : cand){
                int v = e.first, k = e.second;
                printf("%d %d\n", v, k);
            }
        }

    }

}
