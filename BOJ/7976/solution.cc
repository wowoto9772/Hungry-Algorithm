#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000003][2], cnt[1000003][2];

int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i=1; i<=n; i++){
		int e;
		scanf("%d", &e);
		cnt[(i%k)+1][e&1]++;
	}
	
	dp[0][1] = n;
	
	for(int i=1; i<=k; i++){
		dp[i][0] = min(dp[i-1][0] + cnt[i][1], dp[i-1][1] + cnt[i][0]);
		dp[i][1] = min(dp[i-1][0] + cnt[i][0], dp[i-1][1] + cnt[i][1]);
	}
	
	printf("%d\n", dp[k][0]);
	
} 

// https://github.com/koosaga/iamcoder/blob/master/tests/2016_mockicpc/cpp/solI.cpp
// http://ideone.com/LNWUXi