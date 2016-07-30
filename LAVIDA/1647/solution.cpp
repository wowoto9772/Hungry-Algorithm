#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


bool x[2501][2501];
bool chk[2502];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		vector < vector <int> > lnk;
		lnk.resize(n + 1);

		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			lnk[a].push_back(b);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			queue <int> q;
			q.push(i);

			chk[i] = true;

			while (!q.empty()){
				int f = q.front();
				q.pop();

				for (int j = 0; j < lnk[f].size(); j++){
					if (!chk[lnk[f][j]]){
						chk[lnk[f][j]] = true;
						if (lnk[f][j] != i)ans++;
						q.push(lnk[f][j]);
					}
				}
			}

			for (int j = 1; j <= n; j++)chk[j] = false;
		}
		// X != Y

		printf("%d\n", ans);
	}
}