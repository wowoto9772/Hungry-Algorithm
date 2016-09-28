#include <stdio.h>

#include <limits.h>

#include <vector>

using namespace std;

vector < vector < pair <int,int> > > lnk;

int st[3], ed[3];

int dp[103][103][103];

int in[103];

int dy(int a, int b, int c){

	if(a == ed[1] || a == ed[2] || b == ed[0] || b == ed[2] || c == ed[0] || c == ed[1])return INT_MIN>>3;
	if(a == ed[0] && b == ed[1] && c == ed[2])return 0;

	printf("%d %d %d\n", a, b, c);

	int &ret = dp[a][b][c];

	if(ret != -1)return ret;

	ret = INT_MIN>>3;

	for(int i=0; i<lnk[a].size() && a != ed[0]; i++){

		pair<int,int> f = lnk[a][i];

		int na = f.first;

		if(in[na] > 0){
			int re = in[na];
			in[na] = 0;
			ret = max(ret, f.second + dy(na, b, c));
			in[na] = re;
		}

	}

	for(int i=0; i<lnk[b].size() && b != ed[1]; i++){

		pair<int,int> f = lnk[b][i];

		int nb = f.first;

		if(in[nb] > 0){
			int re = in[nb];
			in[nb] = 0;
			ret = max(ret, f.second + dy(a, nb, c));
			in[nb] = re;
		}

	}

	for(int i=0; i<lnk[c].size() && c != ed[2]; i++){

		pair<int,int> f = lnk[c][i];

		int nc = f.first;

		if(in[nc] > 0){
			int re = in[nc];
			in[nc] = 0;
			ret = max(ret, f.second + dy(a, b, nc));
			in[nc] = re;
		}

	}



	return ret;

}

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int n, m;
		scanf("%d %d", &n, &m);

		for(int i=0; i<3; i++)scanf("%d", &st[i]);
		for(int i=0; i<3; i++)scanf("%d", &ed[i]);

		for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)for(int k=1; k<=n; k++)dp[i][j][k] = -1;

		for(int i=1; i<=n; i++)in[i] = 0;

		lnk.clear();

		lnk.resize(n+1);

		for(int i=1; i<=m; i++){

			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			lnk[a].emplace_back(b, c);

			in[b]++;

		}

		int flg = dy(st[0], st[1], st[2]);

		if(flg <= 0)flg = 0;

		printf("(%d)\n", flg);

	}

}

