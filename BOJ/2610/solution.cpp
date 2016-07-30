#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int p[103];
int d[103][103];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)d[i][j] = INT_MAX / 2;

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		d[a][a] = d[b][b] = 0;
		d[a][b] = d[b][a] = 1;

		while (p[a])a = p[a];
		while (p[b])b = p[b];

		if (a != b){
			p[a] = b;
		}
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	vector < vector <int> > cmp;
	cmp.resize(n + 1);

	for (int i = 1; i <= n; i++){
		int a = i;
		while (p[a])a = p[a];
		cmp[a].push_back(i);
	}

	vector <int> ans;

	for (int i = 1; i <= n; i++){
		
		if (cmp[i].empty())continue;

		int tans = INT_MAX, x;
		for (int j = 0; j < cmp[i].size(); j++){
			int tmp = 0;
			for (int k = 0; k < cmp[i].size(); k++){
				tmp = max(tmp, d[cmp[i][j]][cmp[i][k]]);
			}
			if (tans > tmp){
				tans = tmp;
				x = cmp[i][j];
			}
		}

		ans.push_back(x);

	}

	printf("%d\n", ans.size());

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);

}