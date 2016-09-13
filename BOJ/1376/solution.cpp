#include <stdio.h>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

bool used[100003];

vector < vector <int> > lnk;

int num[100003];

void dfs(int f){

	while(true){

		if(num[f] == 0)printf("%d ", f);

		num[f]++;

		int c = 0;

		for(int i=0; i<lnk[f].size(); i++){

			int g = lnk[f][i];

			if(used[g])continue;

			c++;

		}

		if(c == 0)return ;

		if(c&1){
			c++;
			c>>=1;
			for(int i=0; i<lnk[f].size(); i++){
				int g = lnk[f][i];
				if(used[g])continue;
				c--;
				if(c == 0){
					used[g] = true;
					dfs(g);
					break;
				}
			}
		}else{
			for(int i=0; i<lnk[f].size(); i++){
				int g = lnk[f][i];
				if(used[g])continue;
				used[g] = true;
				dfs(g);
				break;
			}
		}

	}

}

int main(){

	int n, m;
	scanf("%d %d", &n, &m);


	lnk.resize(n+1);

	for(int i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for(int i=1; i<=n; i++){
		sort(lnk[i].begin(), lnk[i].end());
		lnk[i].resize(unique(lnk[i].begin(), lnk[i].end()) - lnk[i].begin());
	}

	used[1] = true;

	dfs(1);

}
