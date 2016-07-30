#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <queue>

using namespace std;

int d[103][103];
int c[103][103];
int r[103][103];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			d[i][j] = c[i][j] = INT_MAX;
		}
	}

	for (int i = 1; i <= m; i++){
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);

		c[a][b] = min(c[a][b], k);
	}

	for (int i = 1; i <= n; i++){
		d[i][i] = 0;

		queue <int> q;
		q.push(i);

		while (!q.empty()){
			int f = q.front(); q.pop();
			for (int j = 1; j <= n; j++){
				if (c[f][j] == INT_MAX)continue;
				if (d[i][j] > d[i][f] + c[f][j]){
					d[i][j] = d[i][f] + c[f][j];
					r[i][j] = f;
					q.push(j);
				}
			}
		}

	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (d[i][j] == INT_MAX)d[i][j] = 0;
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i <= n; i++){

		for (int j = 1; j <= n; j++){
			int src = j;
			vector <int> ans;
			while (src){
				ans.push_back(src);
				src = r[i][src];
			}
			if (ans.size() <= 1)printf("0\n");
			else {
				printf("%d ", ans.size());
				for (int k = ans.size() - 1; k >= 0; k--)printf("%d ", ans[k]);
				printf("\n");
			}
		}
	}
	return 0;
}