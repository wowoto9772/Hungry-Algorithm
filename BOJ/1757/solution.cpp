#include <stdio.h>
#include <limits.h>

#include <algorithm>

using namespace std;

int dp[10003][503], w[10003];
int n, m;

int dy(int c, int t){

	if(c >= n){
		if(c == n && t == 0)return 0;
		return INT_MIN;
	}

	int &ret = dp[c][t];

	if(ret != -1)return ret;

	ret = INT_MIN;

	if(t < m){
		ret = max(ret, w[c+1] + dy(c+1, t+1));
	}

	ret = max(ret, dy(c+max(t, 1), 0));

	return ret;

}

int main(){

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)scanf("%d", &w[i]);

	for(int i=0; i<=n; i++)for(int j=0; j<=m; j++){
		dp[i][j] = -1;
	}

	printf("%d\n", dy(0, 0));

}
