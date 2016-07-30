#include <stdio.h>
#include <vector>
#define mod 1000000007

using namespace std;

int dp[8][100003];

vector < vector <int> > lnk;

int dy(int c, int t) {

	if (!t) {
		if (!c)return 1;
		else
			return 0;
	}

	if (dp[c][t] != -1)return dp[c][t];

	dp[c][t] = 0;

	for (int i = 0; i < lnk[c].size(); i++) {
		dp[c][t] += dy(lnk[c][i], t - 1);
		dp[c][t] %= mod;
	}

	return dp[c][t];

}

int main() {

	lnk.resize(8);
	lnk[0].push_back(1); lnk[0].push_back(2);
	lnk[1].push_back(0); lnk[1].push_back(2); lnk[1].push_back(3);
	lnk[2].push_back(0); lnk[2].push_back(1); lnk[2].push_back(3); lnk[2].push_back(4);
	lnk[3].push_back(1); lnk[3].push_back(2); lnk[3].push_back(4); lnk[3].push_back(5);
	lnk[4].push_back(2); lnk[4].push_back(3); lnk[4].push_back(5); lnk[4].push_back(6);
	lnk[5].push_back(3); lnk[5].push_back(4); lnk[5].push_back(7);
	lnk[6].push_back(4); lnk[6].push_back(7);
	lnk[7].push_back(5); lnk[7].push_back(6);

	int t;
	scanf("%d", &t);

	for (int i = 0; i < 8; i++)for (int j = 0; j <= t; j++)dp[i][j] = -1;

	printf("%d\n", dy(0, t));

}