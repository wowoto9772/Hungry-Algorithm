#include <stdio.h>


using namespace std;

using ll = long long;


#define mod 1000000007LL

ll fac[1003] = {1,};

int x[1003];

int n, k;

ll dp[1003][1003];

ll dy(int o, int p){

	if(p == 0)return o == 0;

	ll &ret = dp[o][p];

	if(ret != -1)return ret;

	ret = 0;

	if(o)ret = (dy(o-1, p-1) * o) % mod;

	if(o+1 <= p-1)ret += (dy(o+1, p-1) * (n-o)) % mod;

	return ret %= mod;

}

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		scanf("%d %d", &n, &k);

		int c = 0;

		for(int i=1; i<=n; i++){
			scanf("%d", &x[i]);
			if(x[i] == 1)c++;
		}

		printf("Case #%d: ", ++tc);

		if(k < c || (k-c)&1)printf("0\n");
		else{
			for(int i=0; i<=k; i++)for(int j=0; j<=k; j++)dp[i][j] = -1;
			printf("%lld\n", dy(c, k));
		}

	}
}
