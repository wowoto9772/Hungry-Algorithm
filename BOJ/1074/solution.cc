#include <cstdio>

using namespace std;

int r, c, cnt, ans;

void divide(int r1, int c1, int r2, int c2, int ds){

    if(r < r1 || r2 < r || c < c1 || c2 < c){
        cnt += ds * ds;
        return ;
    }

    if(ds == 2){
        for(int i=r1; i<=r2; i++){
            for(int j=c1; j<=c2; j++){
                if(i == r && j == c){
                    ans = cnt;
                }
                cnt++;
            }
        }
    }else{
        int nds = ds >> 1;
        divide(r1, c1, r1+nds-1, c1+nds-1, nds);
        divide(r1, c1+nds, r1+nds-1, c1+2*nds-1, nds);
        divide(r1+nds, c1, r1+2*nds-1, c1+nds-1, nds);
        divide(r1+nds, c1+nds, r1+2*nds-1, c1+2*nds-1, nds);
    }

}

int main(){

    int N;
    while(scanf("%d %d %d", &N, &r, &c) == 3){

        cnt = ans = 0;
        divide(0, 0, (1<<N)-1, (1<<N)-1, 1<<N);
        printf("%d\n", ans);

    }

}
