#include <cstdio>

using namespace std;
using ll = long long;

double w, l, d;

ll c[23][23];

int main(){

    c[0][0] = 1;
    for(int i=1; i<=20; i++){
        c[i][0] = 1;
        for(int j=1; j<=i; j++){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    
    scanf("%lf %lf %lf", &w, &l, &d);
    
    ll vi[6] = {-20, -10, 0, 10, 20, 30};
    double ans[6] = {};
    for(int i=0; i<=20; i++){
        for(int j=0; i+j<=20; j++){
            for(int k=0; k<5; k++){
                if(vi[k] <= i-j && i-j < vi[k+1]){
                    double v = 1;
                    for(int a=1; a<=i; a++)v *= w;
                    for(int b=1; b<=j; b++)v *= l;
                    for(int c=1; c<=(20-(i+j)); c++)v *= d;
                    ans[k] += v;
                }
            }
        }
    }

    for(int i=0; i<5; i++)printf("%.8lf\n", ans[i]);

}
