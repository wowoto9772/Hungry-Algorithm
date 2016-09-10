#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int s[13];

int nxt[367];
int dp[367];

int pars(int _m, int _d){
	return s[_m-1] + _d;
}

int main(){

	for(int i=1; i<=12; i++)s[i] = s[i-1] + d[i];

	for(int i=1; i<=365; i++)dp[i] = INT_MAX;

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){

		int sx, sy, ax, ay;
		scanf("%d %d %d %d", &sx, &sy, &ax, &ay);

		int a = pars(sx,sy), b = pars(ax,ay);

		nxt[a] = max(nxt[a], b-1);

	}

	int st = pars(3,1), ed = pars(11,30);

	for(int i=1; i<st; i++){
		for(int j=i; j<=nxt[i]; j++)dp[j] = 1;
	}

	int ans = INT_MAX;

	for(int i=st-1; i<=365; i++){
		if(dp[i] == INT_MAX)continue;
		for(int j=i+1; j<=nxt[i+1]; j++)dp[j] = min(dp[j], dp[i]+1);
		if(i >= ed)ans = min(ans, dp[i]);
	}

	if(ans == INT_MAX)ans = 0;

	printf("%d\n", ans);

}
