#include <stdio.h>

#include <vector>

#include <queue>

#include <algorithm>

using namespace std;

#define ll long long

#define ed first
#define c second

vector < vector < pair<int,int> > > nxt; 

int dp[1000003];

int main(){

	int m, n, r;
	scanf("%d %d %d", &m, &n, &r);

	nxt.resize(m+1);

	for(int i=1; i<=n; i++){

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		nxt[a].emplace_back(b, c);

	}

	int ans = 0;

	for(int i=0; i<=m; i++){

		if(i)dp[i] = max(dp[i], dp[i-1]);

		for(int j=0; j<nxt[i].size(); j++){
			pair<int,int> x = nxt[i][j];
			if(x.ed <= m){
				if(x.ed + r > m)ans = max(ans, dp[i] + x.c);
				else{
					dp[x.ed + r] = max(dp[x.ed + r], dp[i] + x.c);
				}
			}
		}

		ans = max(ans, dp[i]);

	}

	printf("%d\n", ans);

}
