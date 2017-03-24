#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    ll m = 1;
    while(m){
        m = a % b;
        a = b;
        b = m;
    }return a;
}

int n, k;
ll dp[1<<15][100];
ll e[17], t[53] = {1}, l[17];

ll dy(int S, int r){
    if(S == (1<<n)-1)return r == 0;
	ll &ret = dp[S][r];
	if(ret != -1)return ret;
	ret = 0;
	for(int i=0; i<n; i++){
		if(S&(1<<i))continue;
		ll d = (r * t[l[i]] + e[i]) % k;
		ret += dy(S|(1<<i), d);
	}
	return ret;
}

char str[17][53];
int main(){
	
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
        l[i] = strlen(str[i]);
    }
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        for(int j=0; j<l[i]; j++)e[i] = (e[i] * 10 + str[i][j] - '0') % k;
    }
    for(int i=1; i<=50; i++)t[i] = (t[i-1] * 10) % k;
    
    for(int i=0; i<(1<<n); i++)for(int j=0; j<k; j++)dp[i][j] = -1;
    ll d = dy(0, 0);
    
    if(d == 0){
    	printf("0/1");
    	return 0;
    }
    
    ll e = 1;
    for(int i=2; i<=n; i++)e *= i;
   
    ll g = gcd(d, e);
    d /= g, e /= g;
    printf("%lld/%lld\n", d, e);

}
