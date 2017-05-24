#include <cstdio>
#include <algorithm>

using namespace std;

int dp[103][103];
int c[103];
int n, k;

int dy(int s, int e){
	int &ret = dp[s][e];
	if(ret != -1)return ret;
	
	if(s+1 <= e-1)ret = 987654321;
	else
		ret = 0;
	
	for(int i=s+1; i<=e-1; i++){
		dp[s][e] = min(dp[s][e], c[e] - c[s] - 2 + dy(s, i) + dy(i, e));
	}
	
	return dp[s][e];
}

int main(){
	int t;
	scanf("%d", &t);
	
	int tc = 0;
	while(t--){
		scanf("%d %d", &n, &k);
		
		for(int i=1; i<=k; i++){
			int a;
			scanf("%d", &a);
			c[i] = a;
		}
		
		c[0] = 0, c[k+1] = n+1;
		for(int i=0; i<=k+1; i++)for(int j=i; j<=k+1; j++)dp[i][j] = -1;
		
		printf("Case #%d: %d\n", ++tc, dy(0, k+1));
	}
}