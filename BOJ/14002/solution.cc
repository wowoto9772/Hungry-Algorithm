#include <vector>
#include <algorithm>

using namespace std;

int e[1003], dp[1003], rev[1003];

int main(){

    int n;
    scanf("%d", &n);

    int ans = 0, x;

    for(int i=1; i<=n; i++)scanf("%d", &e[i]);

    for(int i=1; i<=n; i++){
        dp[i] = 1;
        rev[i] = -1;
        for(int j=1; j<i; j++){
            if(e[j] < e[i]){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    rev[i] = j;
                }
            }
        }
        if(ans < dp[i]){
            ans = dp[i];
            x = i;
        }
    }

    printf("%d\n", ans);

    vector <int> v(ans);
    for(int i=v.size()-1; i>=0; i--){
        v[i] = e[x];
        x = rev[x];
    }

    for(auto &e : v)printf("%d ", e);

}
