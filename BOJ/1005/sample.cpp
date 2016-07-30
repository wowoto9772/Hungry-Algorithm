#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int b[1003];
int in[1003];
int fin[1003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)scanf("%d", &b[i]);

		vector < vector <int> > nxt, pre;
		nxt.resize(n + 1);
		pre.resize(n + 1);

		queue <int> q;
		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			in[b]++;
			nxt[a].push_back(b);
			pre[b].push_back(a);
		}

		for (int i = 1; i <= n; i++){
			if (!in[i]){
				q.emplace(i);
				fin[i] = 0;
			}
		}

		int w;
		scanf("%d", &w);

		while (!q.empty()){
			int c = q.front(); q.pop();
			int prev = 0;

			for (int i = 0; i < pre[c].size(); i++){
				prev = max(prev, fin[pre[c][i]]);
			}

			fin[c] = prev + b[c];

			for (int i = 0; i < nxt[c].size(); i++){
				in[nxt[c][i]]--;
				if (!in[nxt[c][i]]){
					q.push(nxt[c][i]);
				}
			}
		}

		printf("%d\n", fin[w]);
	}
}
