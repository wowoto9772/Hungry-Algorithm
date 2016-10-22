#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int x, y, f, a, b, g;
        scanf("%d %d %d %d %d %d", &x, &y, &f, &a, &b, &g);

        printf("%d\n", abs(x-a)+abs(y-b)+f+g);

    }

}
