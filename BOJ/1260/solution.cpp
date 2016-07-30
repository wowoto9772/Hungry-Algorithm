#include <stdio.h>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

vector < vector <int> > lnk;

bool chk[1003];

void dfs(int c){
	chk[c] = true;
	printf("%d ", c);
	for (int i = 0; i < lnk[c].size(); i++){
		int n = lnk[c][i];
		if (chk[n])continue;
		dfs(n);
	}
}

void bfs(int c){
	printf("\n");
	queue <int> q;
	q.push(c);

	chk[c] = true;

	while (!q.empty()){
		int f = q.front(); q.pop();
		printf("%d ", f);
		for (int i = 0; i < lnk[f].size(); i++){
			int n = lnk[f][i];
			if (!chk[n]){
				chk[n] = true;
				q.push(n);
			}
		}
	}printf("\n");
}

int main(){
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)sort(lnk[i].begin(), lnk[i].end());

	dfs(v);
	for (int i = 1; i <= n; i++)chk[i] = false;
	bfs(v);
}