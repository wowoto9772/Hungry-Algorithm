#include <cstdio>

using namespace std;

int main(){

    int n, v;
    scanf("%d %d", &n, &v);

    for(int i=2; i*i <= n; i++){
        if(n%i)continue;
        printf("No\n");
        return 0;
    }

    n += v * 1000000;

    for(int i=2; i*i<=n; i++){
        if(n%i)continue;
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

}
