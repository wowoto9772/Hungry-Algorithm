#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

#define ll long long

int n, m;
ll dp[1003][1003];

char p1[1003], p2[1003];

int p1x[1003], p1y[1003];
int p2x[1003], p2y[1003];

ll cst(int c, int d){
	ll cp1 = (p1x[c] - p2x[d]) * (p1x[c] - p2x[d]);
	ll cp2 = (p1y[c] - p2y[d]) * (p1y[c] - p2y[d]);
	return cp1 + cp2;
}

ll dy(int c, int d){

	if(c == n && d == m)return 0;

	ll &ret = dp[c][d];

	if(ret != -1)return ret;

	ret = INT_MAX;

	if(c < n){
		ret = min(ret, dy(c+1, d) + cst(c+1, d));
	}

	if(d < m){
		ret = min(ret, dy(c, d+1) + cst(c, d+1));
	}

	if(c < n && d < m){
		ret = min(ret, dy(c+1, d+1) + cst(c+1, d+1));
	}

	return ret;

}

int main(){

	scanf("%d %d", &n, &m);

	for(int i=0; i<=n; i++)for(int j=0; j<=m; j++)dp[i][j] = -1;

	scanf("%d %d", &p1x[0], &p1y[0]);

	scanf("%d %d", &p2x[0], &p2y[0]);

	scanf("%s", p1);

	for(int i=0; i<n; i++){

		p1x[i+1] = p1x[i];
		p1y[i+1] = p1y[i];

		if(p1[i] == 'N'){
			p1y[i+1]++;
		}else if(p1[i] == 'S'){
			p1y[i+1]--;
		}else if(p1[i] == 'E'){
			p1x[i+1]++;
		}else{
			p1x[i+1]--;
		}
	}

	scanf("%s", p2);

	for(int i=0; i<m; i++){

		p2x[i+1] = p2x[i];
		p2y[i+1] = p2y[i];

		if(p2[i] == 'N'){
			p2y[i+1]++;
		}else if(p2[i] == 'S'){
			p2y[i+1]--;
		}else if(p2[i] == 'E'){
			p2x[i+1]++;
		}else{
			p2x[i+1]--;
		}

	}

	printf("%lld", dy(0, 0)); 

}
