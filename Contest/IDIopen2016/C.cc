#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int X, Y;
    scanf("%d%d",&X,&Y);
    if(X==0 && Y==1) {
        puts("ALL GOOD");
    } else if(Y==1) {
        puts("IMPOSSIBLE");
    } else {
        double ans = -(double)X/(double)(Y-1);
        printf("%.10lf\n", ans);
    }
}
