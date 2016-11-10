#include <cstdio>

using namespace std;

int t[53];

int main(){

    int n, l;
    scanf("%d %d", &n, &l);

    int c = 0, d = 0;

    for(int i=1; i<=n; i++){
        scanf("%d", &t[i]);
        d += t[i];
        if(d > l)continue;
        c++;
    }

    printf("%d\n", c);

}
