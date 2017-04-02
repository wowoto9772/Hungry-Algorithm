#include <cstdio>
#include <algorithm>

using namespace std;

int e[53];

int main(){

    int n;
    while(scanf("%d", &n) == 1){
        for(int i=1; i<=n; i++)scanf("%d", &e[i]);
        int s;
        scanf("%d", &s);
        for(int i=1; i<n && s; i++){
            int maxV = -1, p;
            for(int j=i; j<=n && j <= i+s; j++){
                if(maxV < e[j])maxV = e[j], p = j;
            }
            s -= p-i;
            for(int j=p; j>i; j--)swap(e[j], e[j-1]);
        }
        for(int i=1; i<=n; i++)printf("%d ", e[i]);
        printf("\n");
    }

}
