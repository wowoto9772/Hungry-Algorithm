#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

double p[1003][2003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        double pl, pr, ps; // probability (left, right, stop)
        scanf("%d %lf %lf", &n, &pl, &pr);

        ps = 1.0 - pl - pr;

        for(int i=0; i<=n; i++)for(int j=0; j<=2*n; j++){
            p[i][j] = 0.0;
        }

        p[0][n] = 1.0;

        for(int i=0; i<n; i++){
            for(int j=n-i; j<=n+i; j++){
                double q = p[i][j];
                if(q > 0.0){
                    p[i+1][j+1] += q * pr;
                    p[i+1][j] += q * ps;
                    if(j > 0)p[i+1][j-1] += q * pl;
                }
                printf("%lf ", q);
            }printf("\n");
        }

    }

}
