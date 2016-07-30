#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector <int> > nxt;
	nxt.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		nxt[a].push_back(b);
	}

	bool chk[103];
	int less[103] = { 0 }, more[103] = { 0 };
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)chk[j] = false;
		chk[i] = true;

		queue <int> q;
		q.push(i);

		int ans = 0;

		while (!q.empty()){
			int f = q.front(); q.pop();
			for (int j = 0; j < nxt[f].size(); j++){
				int x = nxt[f][j];
				if (chk[x])continue;
				else{
					chk[x] = true;
					less[x]++;
					more[i]++;
					q.push(x);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++){
		printf("%d\n", n - 1 - less[i] - more[i]);
	}
}