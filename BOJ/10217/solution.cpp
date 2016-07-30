#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <vector>
#define min(a, b) (a) < (b) ? (a) : (b)

using namespace std;

class ele{
public:
	int a, c, t;
};

int N, C;

int dp[103][10003];

int dy(int c, int m, const vector < vector <ele> > &L){
	if (c == N)return 0;
	if (dp[c][m] != -1)return dp[c][m];

	dp[c][m] = INT_MAX / 150;

	ele pop;
	for (int i = 0; i < L[c].size(); i++){
		pop = L[c][i];
		if(m + pop.c <= C)dp[c][m] = min(dp[c][m], dy(pop.a, m + pop.c, L) + pop.t);
	}

	return dp[c][m];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int m;
		scanf("%d %d %d", &N, &C, &m);

		vector < vector <ele> > L;
		L.resize(N + 1);

		ele psh;

		for (int i = 1; i <= m; i++){
			int a;
			scanf("%d %d %d %d", &a, &psh.a, &psh.c, &psh.t);
			L[a].push_back(psh);
		}

		memset(dp, 0xff, sizeof(dp));
		int flag = dy(1, 0, L);
		if (flag >= INT_MAX / 150)printf("Poor KCM\n");
		else
			printf("%d\n", flag);
	}
}