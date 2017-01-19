#include <cstdio>
#include <math.h>

using namespace std;

const double pi = acos(-1.0);
double p[10003];

int main(){

    int t;
    scanf("%d", &t);
    
    while(t--){
        int n, f;
        scanf("%d %d", &n, &f);
        
        double MV = 0.0;
        
        for(int i=0; i<n; i++){
            scanf("%lf", &p[i]);
            p[i] *= p[i];
            if(MV < p[i])MV = p[i];
        }

        double l = 0, r = 1.0, mid;
        int acc = 50;

        while(acc--){
            mid = (l + r) / 2;
            
            double x = MV * mid;
                        
            int c = 0;
            
            for(int i=0; i<n; i++){
                c += p[i] / x;
            }
       
            if(f+1 <= c)l = mid;
            else
                r = mid;
        }
        
        printf("%.4lf\n", MV*mid*pi);
    }
}
