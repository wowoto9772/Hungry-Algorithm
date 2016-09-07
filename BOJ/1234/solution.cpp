#include <stdio.h>

#define ll long long

int n;

ll dp[13][103][103][103];

ll fac[13] = {1,};

ll dy(int c, int r, int g, int b){
	
	if(r < 0 || g < 0 || b < 0)return 0;
	if(c == n+1)return 1;

	ll &ret = dp[c][r][g][b];

	if(ret != -1)return ret;

	ret = 0;

	ll way = fac[c] / fac[c/3] / fac[c/3] / fac[c/3];

	if(!(c%3)){
		ret += dy(c+1, r-c/3, g-c/3, b-c/3) * way;
	}
		
	if(!(c&1)){	

		way = fac[c] / fac[c/2] / fac[c/2];

		ret += dy(c+1, r-c/2, g-c/2, b) * way;
		ret += dy(c+1, r-c/2, g, b-c/2) * way;
		ret += dy(c+1, r, g-c/2, b-c/2) * way;
			
	}

	ret += dy(c+1, r-c, g, b);
	ret += dy(c+1, r, g-c, b);
	ret += dy(c+1, r, g, b-c);

	return ret;

}

int main(){

	for(ll i=1; i<=10; i++)fac[i] = fac[i-1] * i;

	int r, g, b;
	scanf("%d %d %d %d", &n, &r, &g, &b);
	
	for(int i=1; i<=n; i++)for(int x=0; x<=r; x++)for(int y=0; y<=g; y++)for(int z=0; z<=b; z++)dp[i][x][y][z] = -1;

	printf("%lld\n", dy(1, r, g, b));

}
