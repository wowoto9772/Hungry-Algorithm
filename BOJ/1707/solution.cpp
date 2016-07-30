#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

bool chk[20003];
bool used[20003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){

		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)chk[i] = false, used[i] = false;

		vector < vector <int> > lnk;

		lnk.resize(n + 1);

		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			lnk[a].push_back(b);
			lnk[b].push_back(a);
		}

		queue <int> q;

		bool flag = false;

		for (int i = 1; i <= n && !flag; i++){

			if (used[i])continue;

			q.push(i);
			
			chk[i] = used[i] = true;

			while (!q.empty() && !flag){
				int f = q.front(); q.pop();
				for (int i = 0; i < lnk[f].size(); i++){
					int v = lnk[f][i];
					if (used[v]){
						if (chk[v] == chk[f]){
							flag = true;
						}
					}
					else{
						used[v] = true;
						chk[v] = !chk[f];
						q.push(v);
					}
				}
			}
		}

		printf("%s\n", flag ? "NO" : "YES");
	}
}