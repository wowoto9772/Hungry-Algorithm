#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

vector < vector <int> > lnk[2];

vector <int> stk, grp;
vector <bool> vst;

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

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	lnk[0].resize(n+1), lnk[1].resize(n+1);

	stk.resize(n);

	grp.resize(n+1);

	vst.resize(n+1);

	for(int i=1; i<n; i++){
		lnk[0][i].push_back(i+1);
		lnk[1][i+1].push_back(i);
	}

	for(int i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		lnk[0][a].push_back(b);
		lnk[1][b].push_back(a);
	}

	for(int i=1; i<=n; i++){
		dfs(0, i);
	}

	for(int i=top-1; i>=0; i--){
		if(grp[stk[i]])continue;
		gtop++;
		dfs(1, stk[i]);
	}

	vector < vector < int > > glnk;
	vector < int > gsize;

	glnk.resize(gtop+1);
	gsize.resize(gtop+1);

	for(int i=1; i<=n; i++){
		gsize[grp[i]]++;
		for(int x=0; x<lnk[0][i].size(); x++){
			int j = lnk[0][i][x];
			glnk[grp[i]].push_back(grp[j]);
		}
	}

	for(int i=1; i<=gtop; i++){
		sort(glnk[i].begin(), glnk[i].end());
		glnk[i].resize(unique(glnk[i].begin(), glnk[i].end()) - glnk[i].begin());
	}

	for(int x=1; x<=n; x++){
		
		int c = 0, d = 0;

		for(int i=1; i<=gtop; i++){
			c += gsize[i];
			if(c == x){
				c = 0;
				d++;
			}else if(c > x){
				break;
			}
		}

		if(c == 0){
			printf("%d\n", d);
			break;
		}

	}

}
