#include <cstdio>

using namespace std;

const int lmod = 1000000007;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int dp[303][1 << 18];
int r, c;

int main(){

	scanf("%d %d", &r, &c);

	if (r < c)swap(r, c);
	dp[0][0] = 1;

	for (int x = 0; x < r*c; x++){
		for (int i = 0; i < (1 << (c + 1)); i++){
			int lt = i & 1, t = i & 2, l = i&(1 << (c));
			int s = i >> 1;
			if (!(((x%c) != 0) && (lt) && (t) && (l))){
				s |= (1 << (c));
				dp[x + 1][s] += dp[x][i];
				if (dp[x + 1][s] >= lmod)dp[x + 1][s] -= lmod;
			}
			s = i >> 1;
			dp[x + 1][s] += dp[x][i];
			if (dp[x + 1][s] >= lmod)dp[x + 1][s] -= lmod;
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << (c + 1)); i++){
		ans += dp[r*c][i];
		if (ans >= lmod)ans -= lmod;
	}

	printf("%d\n", ans);

}