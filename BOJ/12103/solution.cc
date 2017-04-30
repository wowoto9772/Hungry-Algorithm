#include <cstdio>
#include <algorithm>

using namespace std;

int e[1000003];
int dp[1000003][2], cnt[1000003][2];
int odd[1000003][2], rev[1000003][2];
int ans[1000003];

int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
		cnt[(i%k)+1][e[i]&1]++;
	}
	
	dp[0][1] = n;
	
	for(int i=1; i<=k; i++){
		int a = dp[i-1][0] + cnt[i][1], b = dp[i-1][1] + cnt[i][0];
		if(a > b){
			dp[i][0] = b;
			odd[i][0] = 1;
			rev[i][0] = 1;
		}else{
			dp[i][0] = a;
			odd[i][0] = 0;
			rev[i][0] = 0;
		}
		a = dp[i-1][0] + cnt[i][0], b = dp[i-1][1] + cnt[i][1];
		if(a > b){
			dp[i][1] = b;
			odd[i][1] = 0;
			rev[i][1] = 1;
		}else{
			dp[i][1] = a;
			odd[i][1] = 1;
			rev[i][1] = 0;
		}
	}
	
	// 2, 3, 4, ... , k, 1
	
	printf("%d\n", dp[k][0]);
	int top = 0, cur = 0, pt = k;
	while(pt >= 1){
		ans[(++top) % k] = odd[pt][cur];
		cur = rev[pt][cur];
		pt--;
	}
	
	for(int i=top-1; i>=0; i--){
		for(int j=top-i; j<=n; j+=k){
			if((e[j]&1) != ans[i])e[j] = ans[i];
		}
	}
	for(int i=1; i<=n; i++)printf("%d ", e[i]);
	
}