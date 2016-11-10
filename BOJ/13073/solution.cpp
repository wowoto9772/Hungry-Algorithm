#include <cstdio>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d %d %d\n", n*(n+1)/2, n*n, 2*n*(n+1)/2);
    }

}
