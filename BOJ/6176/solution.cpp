#include <stdio.h>

#include <limits.h>

#include <algorithm>

using namespace std;

int n, m;

int s[2503];

int dp[2503];

int dy(int c){

	int &ret = dp[c];

	if(ret != -1)return ret;

	ret = INT_MAX;

	for(int i=1; i<n-c; i++){
		ret = min(ret, s[i] + 2 * m + dy(c+i));
	}

	ret = min(ret, s[n-c] + m + dy(n));

	return ret;

}

int main(){

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		scanf("%d", &s[i]);
		s[i] += s[i-1];
	}

	for(int i=0; i<n; i++){
		dp[i] = -1;
	}

	printf("%d\n", dy(0));

}
