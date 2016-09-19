#include <stdio.h>

#include <algorithm>

using namespace std;

int e[53];

int main(){

    int n, s, d;
    scanf("%d %d %d", &n, &s, &d);

    for(int i=1; i<=n; i++){

        scanf("%d", &e[i]);

    }

    if(n == d && e[d] >= s){
        printf("-1");
        return 0;
    }

    int cnt = 1, rnk = 1;

    for(int i=1; i<=n; i++){
        if(e[i] <= s)break;
        if(i<n && e[i] == e[i+1])cnt++;
        else{
            rnk += cnt;
            cnt = 1;
        }
    }

    printf("%d", rnk);

}
