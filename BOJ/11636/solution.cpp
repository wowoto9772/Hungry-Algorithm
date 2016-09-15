#include <stdio.h>

#include <algorithm>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);
    
    while(t--){

        int p, c;
        scanf("%d", &p);

        int ans = 0;

        while(scanf("%d", &c) == 1 && c){

            ans += max(c - 2*p, 0);

            p = c;

        }

        printf("%d\n", ans);

    }

}
