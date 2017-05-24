#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

ll dp[1<<12][12];
int C[1<<12], n;

ll dy(int c, int s){
	
	ll &ret = dp[c][s];
	if(ret != -1)return ret;
	
	if(c >= 1<<n){
		if(C[c]<s)ret = (1LL << 32);
		else
			ret = 0;
	}else{
		ret = min(C[c]+dy(c*2,s)+dy(c*2+1,s), dy(c*2,s+1)+dy(c*2+1,s+1));
	}
	
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	
	int tc = 0;
	
	while(t--){
		
		scanf("%d", &n);
		for(int i=(2<<n)-1; i>=1; i--)scanf("%d", &C[i]);
		
		for(int i=0; i<(1<<12); i++)for(int j=0; j<12; j++)dp[i][j] = -1;
		printf("Case #%d: %lld\n", ++tc, dy(1, 0));
	}
}