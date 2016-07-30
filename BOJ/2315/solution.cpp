#include <stdio.h>
#include <memory.h>
#include <limits.h>

class ele{
public:
	int p, c;
}I[1003];

int n;
int dp[1002][1002][2];
int s[1002];

int min(int a, int b){ return a < b ? a : b; }
int dy(int l, int r, int g){ // l to r : end
	// if g == 0 : I'm in left side
	if (l == 1 && r == n)return 0;

	if (dp[l][r][g] != -1)return dp[l][r][g];

	dp[l][r][g] = 1000000001;

	int c = s[l - 1] + (s[n] - s[r]);
	int t;

	if (l > 1){
		if (!g)t = I[l].p - I[l - 1].p;
		else{
			t = I[r].p - I[l - 1].p;
		}
		dp[l][r][g] = min(dp[l][r][g], c * t + dy(l - 1, r, 0));
	}

	if (r < n){
		if (g)t = I[r + 1].p - I[r].p;
		else{
			t = I[r + 1].p - I[l].p;
		}
		dp[l][r][g] = min(dp[l][r][g], c * t + dy(l, r + 1, 1));
	}

	return dp[l][r][g];
}

int main(){
	int m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &I[i].p, &I[i].c);
		s[i] += s[i - 1] + I[i].c;
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(m, m, 1));
}