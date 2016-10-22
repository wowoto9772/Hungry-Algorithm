#include <cstdio>
#include <limits.h>
#include <algorithm>

using namespace std;

int dist(int a, int b, int x, int y){
    return abs(a-x)+abs(b-y);
}

int main(){

    int x, y;
    scanf("%d %d", &x, &y);

    int n;
    scanf("%d", &n);

    int p, q, d = INT_MAX;

    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        int e = dist(x, y, a, b);
        if(d > e){
            d = e;
            p = a, q = b;
        }
    }

    printf("%d %d\n", p, q);

}
