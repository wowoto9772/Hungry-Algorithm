#include <cstdio>

using namespace std;

int max(int a, int b){
	if(a > b)return a;
	return b;
}

int dp[17];
int n;

int t[17], p[17];

int dy(int c){
	if(c >= n)return 0;
	if(dp[c] != -1)return dp[c];
	dp[c] = dy(c+1);
	if(c+t[c] <= n)dp[c] = max(dp[c], p[c] + dy(c+t[c]));
	return dp[c];
}

int main(){
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &t[i], &p[i]);
		dp[i] = -1;
	}
	
	printf("%d\n", dy(0));
	
}