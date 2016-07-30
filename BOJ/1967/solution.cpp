#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, c;
	ele(){}
	ele(int a_, int c_){
		a = a_, c = c_;
	}
};

vector < vector <ele> > lnk;

bool chk[10003];
int dp[10003];
int p[10003];

int dy(int c){
	if (dp[c] != -1)return dp[c];

	chk[c] = true;

	dp[c] = 0;

	for (int i = 0; i < lnk[c].size(); i++){
		ele pp = lnk[c][i];

		int n = pp.a, cst = pp.c;

		if (chk[n])continue;

		p[n] = c;
		dp[c] = max(dp[c], cst + dy(n));
	}

	return dp[c];
}

void swp(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int main(){
	int n;
	scanf("%d", &n);

	lnk.resize(n + 1);

	for (int i = 1; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		lnk[a].emplace_back(b, c);
		lnk[b].emplace_back(a, c);

		dp[i] = -1;
	}

	dy(1);

	int ans = 0;
	for (int i = 1; i <= n; i++){

		ans = max(ans, dp[i]);

		int s[2] = { 0 };

		for (int j = 0; j < lnk[i].size(); j++){

			if (s[0] > s[1])swp(s[0], s[1]);

			if (lnk[i][j].a == p[i])continue;
			
			int c = lnk[i][j].c + dp[lnk[i][j].a];
			
			if (s[0] < c)s[0] = c;
		}

		ans = max(ans, s[0] + s[1]);
	}

	printf("%d\n", ans);
}