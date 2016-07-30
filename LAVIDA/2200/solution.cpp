#include <stdio.h>
#include <memory.h>

#include <algorithm>
#include <vector>

using namespace std;

const int inf = 1000000007;
int d[153][153][153];
int pre[153][153][153];

class Edge{
public:
	int a, c;
	bool operator<(const Edge A)const{
		return c > A.c;
	}
};

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m, q;
		scanf("%d %d %d", &n, &m, &q);

		vector <Edge> lnk[153];
		Edge psh;
		int a, b, c;

		for (int i = 1; i <= m; i++){
			scanf("%d %d %d", &a, &b, &c);
			psh.a = b, psh.c = c;
			lnk[a].push_back(psh);
		}

		memset(d, 0x4f, sizeof(d));
		memset(pre, -1, sizeof(pre));

		for (int i = 1; i <= n; i++){
			d[0][i][i] = 0;
			sort(lnk[i].begin(), lnk[i].end());
		}

		for (int k = 1; k<n; k++){
			for (a = 1; a <= n; a++){
				for (b = 1; b <= n; b++){
					if (d[k - 1][a][b] >= inf)continue;
					for (c = 0; c<lnk[b].size(); c++){
						Edge go = lnk[b][c];
						if (go.c > pre[k - 1][a][b]){
							if (d[k][a][go.a] > d[k - 1][a][b] + go.c){
								d[k][a][go.a] = d[k - 1][a][b] + go.c;
								pre[k][a][go.a] = go.c;
							}
						}
						else{
							break;
						}
					}
				}
			}
		}

		for (int Q = 1; Q <= q; Q++){
			scanf("%d %d %d", &a, &b, &c);

			int ans = inf;

			int lm = c > n - 1 ? n - 1 : c;
			for (int i = 0; i <= lm; i++)ans = ans < d[i][a][b] ? ans : d[i][a][b];

			if (ans >= inf)printf("-1\n");
			else
				printf("%d\n", ans);
		}
	}
}