#include <stdio.h>
#include <map>
#define ll long long

using namespace std;

int n;
map< ll, map<int, bool> > dp;

bool dy(ll x, int p){
	if (x >= n)return !p;
	if (dp[x].count(p))return dp[x][p];

	dp[x][p] = !p;
	for (int i = 9; i >= 2; i--){
		if (dy(x*i, !p) == p){
			dp[x][p] = p;
			break;
		}
	}

	return dp[x][p];
}

int main(){
	while (scanf("%d", &n) == 1){
		printf("%s\n", dy(1, 1) ? "Baekjoon wins." : "Donghyuk wins.");
		dp.clear();
	}
}