#include <stdio.h>

#include <math.h>

#include <algorithm>

using namespace std;

int main(){

    long double n, l[3];
    scanf("%Lf", &n);

    for(int i=0; i<3; i++)scanf("%Lf", &l[i]);

    long double le = 0, ri = min({l[0], l[1], l[2]}), ans = 0.0;

    while(ri-le > 1e-10){

        long double m = (le+ri) / 2.0;

        long double d = 1.0;

        for(int i=0; i<3; i++){
            d *= floor(l[i] / m);
        }

        if(d >= n){
            le = m;
            ans = max(ans, m);
        }else{
            ri = m;
        }

    }

    printf("%.10Lf\n", ans);

}
