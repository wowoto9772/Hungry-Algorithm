#include <cstdio>

using namespace std;
using ll = long long;

ll dp[23][23][23];
double w, l, d;

int main(){
    
    scanf("%lf %lf %lf", &w, &l, &d);
    
    dp[0][0][0] = 1;
    for(int i=1; i<=20; i++){
        for(int j=0; j<=i; j++){
            for(int k=0; j+k<=i; k++){
                if(j)dp[i][j][k] += dp[i-1][j-1][k];
                if(k)dp[i][j][k] += dp[i-1][j][k-1];
                dp[i][j][k] += dp[i-1][j][k];
            }
        }
    }
    
    ll tot = 0;
    ll vi[6] = {-20, -10, 0, 10, 20, 30};
    double ans[6] = {};
    for(int i=0; i<=20; i++){ // win
        for(int j=0; i+j<=20; j++){ // lose
            tot += dp[20][i][j];
        }
    }
    for(int i=0; i<=20; i++){
        for(int j=0; i+j<=20; j++){
            for(int k=0; k<5; k++){
                if(vi[k] <= i-j && i-j < vi[k+1]){
                    double v = (double)dp[20][i][j];
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
