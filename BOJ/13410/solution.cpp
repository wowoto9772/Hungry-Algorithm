#include <cstdio>
#include <algorithm>

using namespace std;

int rev(int a){
    int r = 0;
    while(a){
        r = r * 10 + a % 10;
        a /= 10;
    }return r;
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int ans = 0;

    for(int i=1; i<=k; i++){
        ans = max(ans, rev(i*n));
    }

    printf("%d\n", ans);

}
