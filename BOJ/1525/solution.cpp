#include <stdio.h>

#include <queue>

#include <set>

using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int d[4][4];

int e[13];

class ele{
    public:

        int s, c, m;

        ele(){}

        ele(int _s, int _c, int _m){
            s = _s, c = _c, m = _m;
        }

};

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

        queue < ele > q;

        set <int> chk;

        q.emplace(0, 0, flg);

        for(int i=1; i<=9; i++)q.front().s = q.front().s * 10 + e[i];

        int goal = 123456780;

        chk.insert(q.front().s);

        while(!q.empty()){

            ele f = q.front(); q.pop();

            if(f.s == goal){
                printf("%d\n", f.c);
                return 0;
            }

            int v = f.s;


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
                                    e[(x-1)*3+y] = d[x][y];
                                    nv = nv * 10 + d[x][y];
                                }
                            }

                            flg = 0;

                            for(int j=1; j<=9; j++){
                                if(!e[j])continue;
                                for(int k=j+1; k<=9; k++){
                                    if(!e[k])continue;
                                    if(e[j] > e[k])flg++;
                                }


                            }

                            swap(d[a][b], d[na][nb]);

//                            if(f.m < flg)continue;

                            set <int> :: iterator it = chk.lower_bound(nv);

                            if(*it == nv)continue;

                            chk.insert(nv);

                            q.emplace(nv, f.c+1, flg);

                        }

                    }
                }
            }

        }

    }

}
