#include <stdio.h>

#include <vector>

using namespace std;

#define ll long long

#define a first
#define b second

ll dp[13][103];

int main(){

	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);

	dp[0][s] = 1LL;

	vector < pair <int,int> > edge(m);
	
	for(int i=0; i<m; i++){
		
		scanf("%d %d", &edge[i].a, &edge[i].b);

	}

	for(int i=1; i<=t; i++){

		for(auto &e : edge){

			int x = e.a, y = e.b;

			dp[i][x] += dp[i-1][y];
			dp[i][y] += dp[i-1][x];

		}

	}

	ll ans = 0;

	for(int i=0; i<n; i++){
		ans += dp[t][i];
	}

	printf("%lld\n", ans);

}
