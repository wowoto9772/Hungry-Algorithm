#include <stdio.h>
#include <algorithm>

using namespace std;

int e[103][103];
int dp[103][103];

int dy(int n, int m){

	if(m == 0)return 0;

	int &ret = dp[n][m];

	if(ret != -1)return ret;

	ret = 0;

	for(int i=0; i<=n; i++){
		ret = max(ret, e[m][i] + dy(n-i, m-1));
	}

	return ret;

}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &e[i][j]);
		}
	}

	for(int i=0; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dy(n, m));

}
