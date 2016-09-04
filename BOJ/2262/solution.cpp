#include <stdio.h>

#include <limits.h>

#include <set>

#include <algorithm>

using namespace std;

int dp[260][260];

int e[260];

int dy(int l, int r){

	if(l == r)return 0;
	
	int &ret = dp[l][r];

	if(ret != -1)return ret;

	ret = INT_MAX;

	set <int> le, ri;

	for(int i=l; i<=r; i++)ri.insert(e[i]);

	for(int i=l; i<r; i++){
		
		le.insert(e[i]);
		ri.erase(e[i]);

		ret = min(ret, dy(l,i) + dy(i+1,r) + abs((*le.begin())-(*ri.begin())));

	}

	return ret;

}

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
		for(int j=i; j<=n; j++){
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dy(1, n));

}
