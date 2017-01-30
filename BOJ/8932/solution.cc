#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double a[7] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
double b[7] = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
double c[7] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
double p[7];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        for(int i=0; i<7; i++)scanf("%lf", &p[i]);

        long long ans = 0;
        for(int i=0; i<7; i++){
            ans += (long long)(a[i] * pow(max(b[i], p[i]) - min(b[i], p[i]), c[i]));
        }

        printf("%lld\n", ans);

    }

}
