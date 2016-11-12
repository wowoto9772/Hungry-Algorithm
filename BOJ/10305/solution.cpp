#include <cstdio>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int ans = -1, cmp = 0;
        
        int l = 1, r = 1;
        int x, y;

        int n;
        scanf("%d", &n);

        for(int i=1; i<n; i++){
            int e;
            scanf("%d", &e);
            cmp += e;
            if(cmp < 0){
                l = i+1, r = i+1;
                cmp = 0;
            }else{
                r++;
                if(ans < cmp){
                    ans = cmp;
                    x = l, y = r;
                }else if(ans == cmp && y-x < r-l){
                    x = l, y = r;
                }
            }
        }

        if(ans < 0)printf("no good path");
        else{
            printf("%d %d", x, y);
        }

        printf("\n");

    }

}
