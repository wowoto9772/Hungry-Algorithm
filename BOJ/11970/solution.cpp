#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    int x[2], y[2];
    for(int i=0; i<2; i++)scanf("%d %d", &x[i], &y[i]);

    printf("%d\n", (y[0]-x[0]) + (y[1]-x[1]) - max(min(y[0], y[1]) - max(x[0], x[1]), 0));

}
