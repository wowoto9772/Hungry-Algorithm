#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int min(int a, int b){ return a < b ? a : b; }

double cst[202][202];

struct edge { int to, cap, rev; };
vector<edge> G[404];
bool used[404];

class MAX_FLOW{
public:

	void init(int n){
		for (int i = 0; i <= n; i++){
			G[i].clear();
		}
	}

	void add_edge(int from, int to, int cap) {
		edge e;
		e.to = to, e.cap = cap, e.rev = G[to].size();
		G[from].push_back(e);
		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
		G[to].push_back(e);
	}

	int dfs(int v, int t, int f) {
		if (v == t) return f;
		used[v] = 1;
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		while (1) {
			for (int i = 0; i <= t; i++)used[i] = false;
			int f = dfs(s, t, 987654321);
			if (f == 0)return flow;
			flow += f;
		}
		return flow;
	}

}mf;

int sx[202], sy[202], bx[202], by[202];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		for (int i = 1; i <= n; i++){
			scanf("%d %d", &sx[i], &sy[i]);
		}

		for (int i = 1; i <= m; i++){
			scanf("%d %d", &bx[i], &by[i]);
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cst[i][j] = (sx[i] - bx[j])*(sx[i] - bx[j]) + (sy[i] - by[j])*(sy[i] - by[j]);
			}
		}

		int l = 0, r = 2000 * 2000 * 2 + 1, lim;
		int ans = r;

		while (l <= r){
			lim = (l + r) / 2;

			mf.init(n + m + 1);

			for (int i = 1; i <= m; i++){
				mf.add_edge(n + i, n + m + 1, k);
			}
			for (int i = 1; i <= n; i++){
				mf.add_edge(0, i, 1);
				for (int j = 1; j <= m; j++){
					if (cst[i][j] <= lim){
						mf.add_edge(i, n + j, 1);
					}
				}
			}

			int c = mf.max_flow(0, n + m + 1);
			if (c == n){
				if (ans > lim)ans = lim;
				r = lim - 1;
			}
			else{
				l = lim + 1;
			}
		}

		printf("%.9lf\n", sqrt((double)ans));
	}
}