#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

#define ll long long

ll dp[1000003];

ll r, p;

ll dy(int c){

	if(c <= 1)return 0;

	if(dp[c] != -1)return dp[c];

	dp[c] = LLONG_MAX;
	
	for(ll i=1; i<c; i++){

		dp[c] = min(dp[c], i*p + r + dy((c+i)/(i+1)));

	}

	return dp[c];

}

int main(){

	int n;
	scanf("%d", &n);

	scanf("%lld %lld", &r, &p);

	for(int i=1; i<=n; i++)dp[i] = -1;

	printf("%lld\n", dy(n));

}
