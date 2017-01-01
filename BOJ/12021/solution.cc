#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

    double l, r;
    scanf("%lf %lf", &l, &r);

    double ans = sqrt(l) * sqrt(r);

    printf("%.3lf %.3lf\n", ans, ans);

}
