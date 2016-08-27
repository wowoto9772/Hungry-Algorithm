#include <stdio.h>
#include <string.h>

#include <string>

#include <vector>
#include <map>

using namespace std;

char str[23];

vector < vector <int> > lnk[2];

int stk[10003], grp[10003];

bool vst[10003];

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

	int n;
	scanf("%d", &n);

	map <string, int> dwarf;

	lnk[0].resize(10003);
	lnk[1].resize(10003);

	int cnt = 0;

	for(int i=1; i<=n; i++){

		scanf("%s", str);

		string tmp = string(str);

		if(!dwarf[tmp])dwarf[tmp] = ++cnt;

		int a = dwarf[tmp];

		char k;
		scanf(" %c", &k);

		scanf("%s", str);

		tmp = string(str);

		if(!dwarf[tmp])dwarf[tmp] = ++cnt;

		int b = dwarf[tmp];

		if(k == '>'){
			lnk[0][a].push_back(b);
			lnk[1][b].push_back(a);
		}else{
			lnk[0][b].push_back(a);
			lnk[1][a].push_back(b);
		}

	}

	for(int i=1; i<=cnt; i++){
		dfs(0, i);
	}

	for(int i=cnt-1; i>=0; i--){
		if(grp[stk[i]])continue;
		gtop++;
		dfs(1, stk[i]);
	}

	if(gtop != cnt)printf("impossible");
	else
		printf("possible");

}
