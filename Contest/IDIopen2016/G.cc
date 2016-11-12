#include <stdio.h>

#include <cmath>

#include <algorithm>

using namespace std;

long double len[10003];

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++)scanf("%LF", &len[i]);

    long double l = 1.0, r = 1.5, m;

    int ans = 100000003;

    while( (r-l) > 1e-12 ){

        m = (l+r) / 2.0;

        int c = 0;
        int cc = 0;

        for(int i=1; i<=n; i++){

            long double d = (len[i] / m) + 1e-4;

            cc += (int)d;

            d -= fmod((long double)len[i], m) <= 1e-12;

            c += max(0, (int)d);

        }

        printf("%.15Lf %.15Lf %d\n", l, r, cc);

        if(cc >= k){

            ans = min(ans, c);
            
            l = m;

        }else{

            r = m;

        }

    }



    printf("%d\n", ans);

}
