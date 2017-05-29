#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){

        int n;
        scanf("%d", &n);

        int ans = 0;

        for(int i=2; i<n; i++){
            int v = n;
            int c = 0;
            while(v){
                if(v%i == 1)c++;
                else{
                    c = -1;
                    break;
                }
                v /= i;
            }
            if(c != -1){
                ans = i;
                break;
            }
        }

        printf("Case #%d: %d\n", ++tc, ans);

    }

}
