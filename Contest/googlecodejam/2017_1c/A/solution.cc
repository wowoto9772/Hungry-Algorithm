#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

class ele{
    public:
        double r, s;
        bool operator<(const ele &A)const{
            if(r == A.r)return s > A.s;
            return r > A.r;
        }
}e[1003];
const double pi = acos(-1.0);

double dp[1003][1003];
int n, k;

double dy(int i, int j){
    if(i == n-1){
        if(j == k)return 0.0;
        else
            return -100000000000000000;
    }
    if(dp[i][j] > -1000000000000000000)return dp[i][j];
    if(j+1 <= k)dp[i][j] = dy(i+1, j+1) + e[i+1].s;
    dp[i][j] = max(dp[i][j], dy(i+1, j));
    return dp[i][j];
}

int main(){

    int t;
    scanf("%d", &t);

    int tc = 0;

    while(t--){
        scanf("%d %d", &n, &k);

        for(int i=0; i<n; i++){
            scanf("%lf %lf", &e[i].r, &e[i].s);
            e[i].s *= e[i].r * 2 * pi;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1000000000000000000;
            }
        }

        sort(e, e+n);
        double ans = 0;
        for(int i=0; i<=n-k; i++){
            ans = max(ans, dy(i, 1) + e[i].r * e[i].r * pi + e[i].s);
        }
        printf("Case #%d: ", ++tc);
        printf("%.9lf\n", ans);
    }

}
