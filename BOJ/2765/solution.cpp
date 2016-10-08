#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main(){

    int tc = 0;

    double r, c, t;
    while(scanf("%lf %lf %lf", &r, &c, &t) == 3){
        r *= pi;
        r *= c;
        r *= 1.578282828 * 1e-5;
        if(fabs(c) <= 1e-9)continue;
        printf("Trip #%d: %.2lf %.2lf\n", ++tc, r, 3600.0*r/(double)t);
    }

}
