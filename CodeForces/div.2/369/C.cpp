#include <stdio.h>
#include <algorithm>

#define ll long long

using namespace std;

#define LMAX (1LL<<59)

int e[103];

ll dp[103][103][103];

int pay[103][103];

int n, m, k;

ll dy(int a, int b, int c){ // a th, b color, conti c

	ll &ret = dp[a][b][c];

	if(a == n+1){
		if(c == k)return 0;
		return LMAX;
	}else if(c > k){
		return LMAX;
	}

	if(ret != -1)return ret;

	ret = LMAX;

	if(e[a]){
		if(b == e[a]){
			ret = min(ret, dy(a+1, b, c));
		}else{
			ret = min(ret, dy(a+1, e[a], c+1));
		}
	}else{
		for(int j=1; j<=m; j++){
			if(b == j){
				ret = min(ret, pay[a][j] + dy(a+1, b, c));
			}else{
				ret = min(ret, pay[a][j] + dy(a+1, j, c+1));
			}
		}
	}

	return ret;

}

int main(){

	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &pay[i][j]);
		}
	}

	for(int x=0; x<=n; x++){
		for(int y=0; y<=m; y++){
			for(int z=0; z<=k; z++){
				dp[x][y][z] = -1;
			}
		}
	}

	ll flg = dy(1, 0, 0);

	if(flg >= LMAX)flg = -1;

	printf("%lld\n", flg);

}
