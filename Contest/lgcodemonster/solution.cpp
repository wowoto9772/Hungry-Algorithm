#include <cstdio>
#include <limits.h>
#include <cmath>
#include <algorithm>

using namespace std;

double dp[2][100003];
int x[100003];
int y[3][100003];

double dist(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){

//    freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            scanf("%d %d %d", &x[i], &y[0][i], &y[1][i]);
        }

        double ans = LLONG_MAX;

        for(int i=2; i<=n; i++){
            if(i == 2){
                vector <int> _Y;
                _Y.push_back(y[0][1]);
                _Y.push_back(y[1][1]);
                _Y.push_back(y[0][2]);
                _Y.push_back(y[1][2]);
                if(i == n){
                    for(int j=0; j<_Y.size(); j++){
                        for(int k=0; k<_Y.size(); k++){
                            if(y[0][1] <= _Y[j] && _Y[j] <= y[1][1]){
                                if(y[0][2] <= _Y[k] && _Y[k] <= y[1][2]){
                                    ans = min(ans, dist(x[1], _Y[j], x[2], _Y[k]));
                                }
                            }
                        }
                    }
                }else{
                    for(auto &Y : _Y){
                        if(y[0][1] <= Y && Y <= y[1][1]){
                            dp[0][i] = min(dp[0][i-1] + dist(x[i-1], Y, x[i], y[0][i]), dp[1][i-1] + dist(x[i-1], Y, x[i], y[0][i]));
                            dp[1][i] = min(dp[0][i-1] + dist(x[i-1], Y, x[i], y[1][i]), dp[1][i-1] + dist(x[i-1], Y, x[i], y[1][i]));
                        }
                    }
                }
            }else if(i != n){
                dp[0][i] = min(dp[0][i-1] + dist(x[i-1], y[0][i-1], x[i], y[0][i]), dp[1][i-1] + dist(x[i-1], y[1][i-1], x[i], y[0][i]));
                dp[1][i] = min(dp[0][i-1] + dist(x[i-1], y[0][i-1], x[i], y[1][i]), dp[1][i-1] + dist(x[i-1], y[1][i-1], x[i], y[1][i]));
            }else{
                vector <int> _Y;
                _Y.push_back(y[0][i-1]);
                _Y.push_back(y[1][i-1]);
                _Y.push_back(y[0][i]);
                _Y.push_back(y[1][i]);
                for(int j=0; j<_Y.size(); j++){
                    if(y[0][n] <= _Y[j] && _Y[j] <= y[1][n]){
                        ans = min(ans, min(dp[0][i-1] + dist(x[i-1], y[0][i-1], x[i], _Y[j]), dp[1][i-1] + dist(x[i-1], y[1][i-1], x[i], _Y[j])));
                    }
                }
            }
        }

        printf("%.2lf\n", ans);

    }

}
