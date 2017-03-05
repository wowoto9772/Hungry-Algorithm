#include <cstdio>
#include <algorithm>

using namespace std;

int e[1003] = {-1, };

int main(){
    
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    int ans = 0;

    for(int i=0; i<=n; i++){
        int p = -2, c = 0;
        for(int j=1; j<=n; j++){
            if(e[i] == e[j])continue;
            if(p == e[j]){
                c++;
            }else{
                p = e[j], c = 1;
            }
            ans = max(ans, c);
        }
    }

    printf("%d\n", ans);

}
