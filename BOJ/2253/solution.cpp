#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

bool cant[10003];

int n;

int dp[10003][203];

int dy(int c, int k){

	if(c == n)return 0;	

	int &ret = dp[c][k];

	if(ret != -1)return ret;

	ret = INT_MAX >> 3;

	int l = k-1, r = k+1;

	if(l < 1)l = 1;

	for(int s=l; s<=r && s <= 200; s++){
		if(c + s > n)continue;
		if(cant[c+s])continue;
		ret = min(ret, 1 + dy(c+s, s));
	}

	return ret;

}

int main(){

	int k;
	scanf("%d %d", &n, &k);

	for(int i=1; i<=n; i++)for(int j=0; j<=200; j++)dp[i][j] = -1;

	for(int i=1; i<=k; i++){
		int x;
		scanf("%d", &x);

		cant[x] = true;
	}

	int flg = dy(1, 0);

	if(flg >= INT_MAX>>3)flg = -1;

	printf("%d\n", flg);

}
