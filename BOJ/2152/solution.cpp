#include <stdio.h>

#include <limits.h>

#include <vector>

#include <algorithm>

using namespace std;

vector < vector <int> > lnk[2];

vector < int > stk, grp;

vector < bool > vst;

int top, gtop;

void dfs(int t, int c){
	if(!t){
		if(vst[c])return ;
		vst[c] = true;
	}else{
		if(grp[c])return ;
		grp[c] = gtop;
	}

	for(int i=0; i<lnk[t][c].size(); i++){
		dfs(t, lnk[t][c][i]);
	}

	if(!t)stk[top++] = c;
}

int st, ed;

vector < vector <int> > glnk;
vector < int > gsize;

int dp[10003];

int dy(int c){

	if(c == grp[ed])return 0;

	int &ret = dp[c];

	if(ret != -1)return ret;

	ret = INT_MIN >> 3;

	for(int i=0; i<glnk[c].size(); i++){
		int nc = glnk[c][i];
		ret = max(ret, gsize[nc] + dy(nc));
	}

	return ret;

}

int main(){

	int n, m;
	scanf("%d %d %d %d", &n, &m, &st, &ed);

	lnk[0].resize(n+1);
	lnk[1].resize(n+1);

	stk.resize(n);
	grp.resize(n+1);
	vst.resize(n+1);

	for(int i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		lnk[0][a].push_back(b);
		lnk[1][b].push_back(a);
	}

	for(int i=1; i<=n; i++)dfs(0, i);

	for(int i=top-1; i>=0; i--){
		if(grp[stk[i]])continue;
		gtop++;
		dfs(1, stk[i]);
	}

	glnk.resize(gtop+1);
	gsize.resize(gtop+1);

	for(int i=1; i<=n; i++){
		gsize[grp[i]]++;
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<lnk[0][i].size(); j++){
			glnk[grp[i]].push_back(grp[lnk[0][i][j]]);
		}
	}

	for(int i=1; i<=gtop; i++){
		sort(glnk[i].begin(), glnk[i].end());
		glnk[i].resize(unique(glnk[i].begin(), glnk[i].end()) - glnk[i].begin());
	}

	for(int i=1; i<=gtop; i++)dp[i] = -1;

	int flg = gsize[grp[st]] + dy(grp[st]);

	if(flg < 0)flg = 0;

	printf("%d", flg);

}
