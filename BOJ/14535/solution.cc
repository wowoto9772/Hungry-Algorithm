#include <cstdio>

using namespace std;

char o[12][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main(){
    
    int tc = 0;
    int n;
    while(scanf("%d", &n) == 1 && n){
        printf("Case #%d:\n", ++tc);
        int c[14] = {};
        for(int i=0; i<n; i++){
            int m;
            scanf("%*d %d %*d", &m);
            c[--m]++;
        }
        for(int i=0; i<12; i++){
            printf("%s:", o[i]);
            for(int j=1; j<=c[i]; j++)printf("*");
            printf("\n");
        }
    }

}