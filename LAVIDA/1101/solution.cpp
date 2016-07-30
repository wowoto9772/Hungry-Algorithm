#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		int a, b;
		vector < vector <int> > P, N;
		P.resize(n + 1);
		N.resize(n + 1);

		for (int i = 1; i <= m; i++){
			scanf("%d %d", &a, &b);
			P[b].push_back(a);
			N[a].push_back(b);
		}

		queue <int> Q, C;
		bool e[1003] = { 0 };
		
		for (int i = 1; i <= n; i++){
			if (!P[i].size()){
				Q.push(i);
				C.push(0);
			}
		}

		int ans = 0;

		while (!Q.empty()){
			int c = Q.front(), x = C.front();
			Q.pop(), C.pop();
			e[c] = true;
			ans = ans < x ? x : ans;
			for (int i = 0; i < N[c].size(); i++){
				int nxt = N[c][i];
				bool flag = false;
				for (int j = 0; !flag && j < P[nxt].size(); j++){
					if (!e[P[nxt][j]])flag = true;
				}
				if (!flag){
					Q.push(nxt);
					C.push(x + 1);
				}
			}
		}
		printf("%d\n", ans+1);
	}
}