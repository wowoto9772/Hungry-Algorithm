#include <stdio.h>

#define ll long long

int e[103];

ll dp[103][103];

int n, k;

ll dy(int c, int m){

	ll &ret = dp[c][m];

	if(m == k)return 1;
	if(ret != -1)return ret;

	ret = 0;

	for(int i=c+1; i<=n; i++){
		if(e[c] < e[i]){
			ret += dy(i, m+1);
		}
	}

	return ret;

}

int main(){

	while(scanf("%d %d", &n, &k) == 2){

		if(!(n|k))break;

		for(int i=1; i<=n; i++)scanf("%d", &e[i]);

		for(int i=1; i<=n; i++){
			for(int j=1; j<=k; j++){
				dp[i][j] = -1;
			}
		}

		ll ans = 0;

		for(int i=1; i<=n; i++){
			ans += dy(i, 1);
		}

		printf("%lld\n", ans);

	}

}
