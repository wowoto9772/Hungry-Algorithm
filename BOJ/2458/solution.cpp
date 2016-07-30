#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int low[505], hi[505];
bool chk[505];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector <int> > big;
	big.resize(n + 1);
	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		big[a].push_back(b);
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)chk[j] = false;
		queue <int> q;
		q.push(i);
		chk[i] = true;
		while (!q.empty()){
			int f = q.front(); q.pop();
			for (int j = 0; j < big[f].size(); j++){
				if (!chk[big[f][j]]){
					hi[i]++;
					low[big[f][j]]++;
					q.push(big[f][j]);
					chk[big[f][j]] = true;
				}
			}
		}
	}

	int c = 0;
	for (int i = 1; i <= n; i++)if (low[i] + hi[i] == n - 1)c++;

	printf("%d\n", c);
}