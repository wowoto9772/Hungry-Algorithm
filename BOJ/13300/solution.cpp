#include <cstdio>

using namespace std;

int x[2][7];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int c = 0;

    for(int i=1; i<=n; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        x[a][b]++;
    }

    for(int i=1; i<=6; i++){

        int d = x[0][i]/k + ((x[0][i]%k) ? 1 : 0);
        d += x[1][i]/k + ((x[1][i]%k) ? 1 : 0);

        c += d;
    }

    printf("%d\n", c);

}
