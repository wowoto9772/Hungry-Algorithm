#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[2003][103][13], use[2003][103][13];
int a[203];
int n;

int dy(int d, int c, int m){

	if(c == n)return 0;

	int &ret = dp[d][c][m];
	int &cln = use[d][c][m];

	if(ret != -1)return ret;

	ret = (d + a[c]) * a[c+1] + dy(d + a[c], c+1, m);
	cln = 0;
	if(m){
		ret = min(ret, dy(0, c+1, m-1));
		if(ret == dy(0, c+1, m-1))cln = 1;
	}

	return ret;

}

int main(){

	int m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(0, 0, m));

	int d = 0, c = 0;

	while(c < n){
		if(use[d][c][m]){
			d = 0;
			m--;
			printf("%d ", c);
		}else{
			d += a[c];
		}
		c++;
	}

}
