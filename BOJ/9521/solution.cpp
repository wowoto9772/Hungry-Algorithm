#include <stdio.h>
#define mod 1000000007LL

#define ll long long

int f[1000003];
int dp[1000003]; 
// dp[x] : x's order

ll color[1000003] = { 1, };

int main(){

	int n;
	ll k;
	scanf("%d %lld", &n, &k);

	color[1] = k;
	color[2] = (k*(k - 1)) % mod;
	color[3] = (k*(k - 1)*(k - 2)) % mod;

	for (int i = 4; i <= n; i++){
		color[i] = (k - 1)*color[i - 2];
		color[i] += (k - 2)*color[i - 1];
		color[i] %= mod;
	}

	for (int i = 1; i <= n; i++){
		scanf("%d", &f[i]);
	}

	ll ans = 1;
	int tot = 1;

	int pre = 0; // pre_processed

	for (int i = 1; i <= n; i++){
		if (dp[i])continue;

		int tmp;
		int cur = i;
		while (true){
			// count 'current components' (cycle)
			if (dp[cur]){
				if (dp[cur] < dp[i])tmp = 0; // pre processed
				else
					tmp = tot - dp[cur];

				break;
			}
			else{
				dp[cur] = tot++;
				cur = f[cur];
			}
		}

		pre += tmp;
		ans *= color[tmp]; // color on past
		ans %= mod;
	}

	for (int i = 1; i <= n - pre; i++){ 
		// have to proess
		ans *= k - 1;
		ans %= mod;
	}

	printf("%lld\n", ans);
}