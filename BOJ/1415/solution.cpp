#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using ll = long long;

using namespace std;

int n;

ll dp[2][500002][2];

bool notPrime[500003] = {true, true};

int main(){

    scanf("%d", &n);

    int tot = 0;

    map <int,int> exist;
    vector <int> val, cnt;
    int top = 0;

    for(int i=0; i<n; i++){
        int e;
        scanf("%d", &e);
        tot += e;
        if(exist.find(e) == exist.end()){
            exist[e] = top++;
            val.push_back(e);
            cnt.push_back(0);
        }
        cnt[exist[e]]++;
    }

    for(int i=2; i*i <= tot; i++){
        if(!notPrime[i]){
            for(int j=i*i; j<=tot; j+=i)notPrime[j] = true;
        }
    }

    n = top;

    // use toggle
    
    ll ans = 0;
   
    dp[0][0][0] = 1;

    for(int i=0; i<n; i++){
        int p = i&1;
        int q = 1^p;
        for(int j=0; j<=tot; j++){
            dp[q][j][0] = dp[p][j][0] + dp[p][j][1];
            dp[q][j][1] = 0;
        }
        for(int j=0; j<tot; j++){
            for(int k=1; k<=cnt[i]; k++){
                int v = k*val[i]+j;
                if(v > tot)break;
                dp[q][v][1] += dp[q][j][0];
            }
        }
        for(int j=2; j<=tot; j++){
            if(!notPrime[j])ans += dp[q][j][1];
        }
    }

    printf("%lld\n", ans);

}

