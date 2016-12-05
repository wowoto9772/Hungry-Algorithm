#include <cstdio>
#include <algorithm>

using namespace std;

bool dp[200003] = {true,};
int s[103];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n, e;
        scanf("%d %d", &n, &e);

        int v = 0;

        for(int i=1; i<=n; i++){
            scanf("%d", &s[i]);
            v += s[i];
        }

        if(v * 2 < e)printf("FULL\n");
        else{
            for(int i=1; i<=2000*n; i++)dp[i] = false;
            for(int i=1; i<=n; i++){
                for(int j=v-s[i]; j>=0; j--){
                    dp[j+s[i]] |= dp[j];
                }
            }
            for(int i=0; i<=2000*n; i++){
                if(dp[i] && 2*i >= e){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }

}
