#include <vector>
#include <algorithm>

using namespace std;

int e[1000003], dp[1000003], rev[1000003];

int main(){

    int n;
    scanf("%d", &n);

    int top = 0;

    for(int i=0; i<n; i++){
        scanf("%d", &e[i]);
    }

    for(int i=0; i<n; i++){
        if(!top){
            dp[top++] = i;
        }else if(e[dp[top-1]] < e[i]){
            rev[i] = dp[top-1];
            dp[top++] = i;
        }else{
            int l = 0, r = top - 1, m;
            while( l <= r ){
                m = (l+r) / 2;
                if(e[dp[m]] >= e[i])r = m - 1;
                else{
                    l = m + 1;
                }
            }

            if(e[dp[m]] < e[i])m++;
            dp[m] = i;
            if(m)rev[i] = dp[m-1];
            top = max(m+1, top);
        }
    }

    printf("%d\n", top);
    vector <int> v(top);
    int j = dp[top-1];
    for(int i=v.size()-1; i>=0; i--){
        v[i] = e[j];
        j = rev[j];
    }
    for(auto &x : v)printf("%d ", x);

}
