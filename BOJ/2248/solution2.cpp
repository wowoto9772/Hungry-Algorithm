#include <cstdio>

using namespace std;

using ll = long long;

int N, L;
ll l;

ll dp[33][33];

ll dy(int c, int m){

    if(c == N){
        return 1;
    }

    ll &ret = dp[c][m];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    ret += dy(c+1, m);

    if(m < L){

        ret += dy(c+1, m+1);

    }

    return ret;

}

int ans[33];

void findAnswer(int c, int m){

    if(c == N){
        for(int i=0; i<N; i++)printf("%d", ans[i]);
        return ;
    }

    ll flg = dy(c+1, m);

    if(l < flg){

        ans[c] = 0;

        findAnswer(c+1, m);

    }else{

        l -= flg;

        ans[c] = 1;

        findAnswer(c+1, m+1);

    }

}

int main(){

    scanf("%d %d %lld", &N, &L, &l);

    for(int i=0; i<N; i++)for(int j=0; j<=L; j++)dp[i][j] = -1;

    l--;

    dy(0, 0);

    findAnswer(0, 0);

}

/*

   00000

   00001
   00010
   00011
   00100
   00101

   00110
   00111
   01000
   01001
   01010

   01011
   01100
   01101
   01110
   10000

   10001
   10010
   10011


*/
