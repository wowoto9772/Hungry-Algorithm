#include <cstdio>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        n++;
        n >>= 1;
        printf("%d\n", n*n);
    }

}
