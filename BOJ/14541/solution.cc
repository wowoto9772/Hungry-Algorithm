#include <cstdio>

using namespace std;

int main(){
    
    int n;
    while(scanf("%d", &n) == 1){
        if(n == -1)break;
        int d = 0;
        int p = 0;
        for(int i=0; i<n; i++){
            int s, t;
            scanf("%d %d", &s, &t);
            d += (t-p) * s;
            p = t;
        }
        printf("%d miles\n", d);
    }

}