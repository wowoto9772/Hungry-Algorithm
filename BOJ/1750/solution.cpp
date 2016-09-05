#include <stdio.h>

#include <map>

using namespace std;

int gcd(int a, int b){

	int m = 1;

	while(m){
		m = a % b;
		a = b;
		b = m;
	}

	return a;
}

#define mod 10000003

map < int, map < int, int > > dp;

int e[103];

int n;

int dy(int c, int r){

	if(c == n)return r == 1;

	if(dp[c].find(r) != dp[c].end())return dp[c][r];

	dp[c][r] = 0;

	dp[c][r] += dy(c+1, r);

	if(r == 0)dp[c][r] += dy(c+1, e[c+1]);
	else
		dp[c][r] += dy(c+1, gcd(r, e[c+1]));

	return dp[c][r] %= mod;

}

int main(){

	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
	}

	printf("%d\n", dy(0, 0));

}
