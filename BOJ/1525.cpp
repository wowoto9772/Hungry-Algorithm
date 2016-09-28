#include <stdio.h>

#include <queue>

#include <set>

using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int d[4][4];

int e[13];

int main(){

    int flg = 0;

    for(int i=1; i<=9; i++){
        scanf("%d", &e[i]);
    }

    for(int i=1; i<=9; i++){

        if(e[i]){
            for(int j=i+1; j<=9; j++){
                if(e[j]){
                    if(e[i] > e[j])flg++;
                }
            }
        }

    }

    if(flg&1)printf("-1\n");
    else{

        queue < pair <int,int> > q;

        set <int> chk;

        q.emplace(0, 0);

        for(int i=1; i<=9; i++)q.front().first = q.front().first * 10 + e[i];

        int goal = 123456780;

        chk.insert(q.front().first);

        while(!q.empty()){

            pair <int,int> f = q.front(); q.pop();

            if(f.first == goal){
                printf("%d\n", f.second);
                return 0;
            }

            int v = f.first;

            printf("%d\n", v);

            for(int i=3; i>=1; i--){
                for(int j=3; j>=1; j--){
                    d[i][j] = v % 10;
                    v /= 10;
                }
            }

            for(int a=1; a<=3; a++){
                for(int b=1; b<=3; b++){
                    if(d[a][b] == 0){
                        
                        for(int i=0; i<4; i++){
                            
                            int na = a + dr[i], nb = b + dc[i];

                            if(na < 1 || nb < 1 || na > 3 || nb > 3)continue;

                            swap(d[a][b], d[na][nb]);

                            int nv = 0;

                            for(int x=1; x<=3; x++){
                                for(int y=1; y<=3; y++){
                                    nv = nv * 10 + d[x][y];
                                }
                            }

                            set <int> :: iterator it = chk.lower_bound(nv);
                            
                            if(*it == nv)continue;

                            chk.insert(nv);

                            q.emplace(nv, f.second+1);

                            swap(d[a][b], d[na][nb]);

                        }

                    }
                }
            }

        }

    }

}
