#include <cstdio>
#include <vector>

using namespace std;

int main(){

    int v;
    while(scanf("%d", &v) == 1 && v >= 0){
        if(v == 0)printf("0\n");
        else{
            bool chk[100*2+3] = {};
            chk[v] = true;
            while(scanf("%d", &v) == 1 && v){
                chk[v] = true;
            }
            int ans = 0;
            for(int i=1; i<=100; i++){
                if(chk[i] && chk[i<<1])ans++;
            }
            printf("%d\n", ans);
        }
    }

}
