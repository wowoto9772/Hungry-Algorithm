#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int in[32003];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector <int> > nxt;
	nxt.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		in[b]++;
		nxt[a].push_back(b);
	}

	queue <int> q;

	for (int i = 1; i <= n; i++){
		if (!in[i])q.push(i);
	}

	while (!q.empty()){
		int c = q.front(); q.pop();

		printf("%d ", c);

		for (int i = 0; i < nxt[c].size(); i++){
			int x = nxt[c][i];
			in[x]--;
			if (!in[x]){
				q.push(x);
			}
		}
	}
}