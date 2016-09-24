#include <cstdio>

using namespace std;

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int x = 0;

    for(int i=1; i<=n; i++){

        int v = i;

        for(int j=2; j*j <= v && j <= k; j++){

            while(!(v%j))v /= j;

        }

        if(v <= k)x++;

    }

    printf("%d\n", x);

}
