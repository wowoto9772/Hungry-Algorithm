#include <stdio.h>
#include <algorithm>

using namespace std;

#define mod 1000000

int dp[4004][204];
int c[204];

int dy(int m, int v){

	int &ret = dp[m][v];

	if(m == 0)return 1;
	else if(v == 0)return 0;

	if(ret != -1)return ret;

	ret = 0;

	ret += dy(m, v-1);

	for(int i=1; i<=min(m, c[v]); i++){
		ret += dy(m-i, v-1);
		ret %= mod;
	}

	return ret;

}

int main(){

	int T, A, S, B;
	scanf("%d %d %d %d", &T, &A, &S, &B);

	for(int i=1; i<=A; i++){
		int v;
		scanf("%d", &v);

		c[v]++;
	}

	for(int i=1; i<=T; i++){
		for(int j=1; j<=A; j++)dp[j][i] = -1;
	}

	int ans = 0;

	for(int i=min(S,B); i<=max(S,B); i++){
		ans += dy(i, T);
		ans %= mod;
	}

	printf("%d\n", ans);

}
