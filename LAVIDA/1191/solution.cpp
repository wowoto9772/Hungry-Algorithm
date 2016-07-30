#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int src[52], snk[52];
int cap[2604][2604];
int flow[2604][2604];
int P[2604];
vector < int > link[2604];

int m(int a, int b){ return a < b ? a : b; }

int MaximumFlow(int source, int sink){ // fordFulkerson

	int ret = 0;

	while (true){

		queue <int> Q;

		memset(P, 0xff, sizeof(P));
		P[source] = source; // argument path
		Q.push(source);

		while (!Q.empty() && P[sink] == -1){
			int now = Q.front(); Q.pop();

			for (int i = 0; i < link[now].size(); i++){
				int nxt = link[now][i];
				if (cap[now][nxt] - flow[now][nxt] > 0 && P[nxt] == -1){
					// amount to use
					Q.push(nxt);
					P[nxt] = now;
				}
			}
		}

		if (P[sink] == -1)break; // end condition

		int amount = INT_MAX;

		for (int p = sink; p != source; p = P[p]){
			amount = m(amount, cap[P[p]][p] - flow[P[p]][p]);
		}

		for (int p = sink; p != source; p = P[p]){
			flow[P[p]][p] += amount;
			flow[p][P[p]] -= amount;
		}

		ret += amount;
	}

	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);

	int l = 0, r = 0;

	int goal = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &snk[i]);
		goal += snk[i];
		r = r < snk[i] ? snk[i] : r;
	}
	for (int i = 1; i <= n; i++)scanf("%d", &src[i]);

	int limit;

	bool flag = false;

	int ans = INT_MAX;
	int ans2[52][52];

	while (l <= r){
		limit = (l + r) / 2;

		//memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));

		for (int i = 1; i <= n; i++){
			if (!flag){
				cap[0][i] = src[i];
				cap[n*n + n + i][n*n + 2 * n + 1] = snk[i];
				link[0].push_back(i); // forward
				link[n*n + n + i].push_back(n*n + 2 * n + 1); // forward
			}
			for (int j = 1; j <= n; j++){
				int x = n + n * (i - 1) + j;
				cap[j][x] = limit;
				cap[x][n*n + n + i] = limit;
				if (!flag){
					link[x].push_back(n*n + n + i); // forward
					link[n*n + n + i].push_back(x); // backward
					link[j].push_back(x); // forward
					link[x].push_back(j); // backward
				}
			}
		}

		int cmp = MaximumFlow(0, n*n + 2 * n + 1);
		if (cmp >= goal){
			r = limit - 1;
			if (ans > limit){
				ans = limit;
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						int x = n + n * (i - 1) + j;
						ans2[i][j] = flow[j][x];
					}
				}
			}
		}
		else if (cmp < goal){
			l = limit + 1;
		}

		flag = true;
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < n; j++)printf("%d ", ans2[i][j]);
		printf("%d\n", ans2[i][n]);
	}
}

//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//struct edge { int to, cap, rev, rcp; };
//class MaxFlow{
//public:
//	vector<edge> G[2603];
//	bool used[2603];
//
//	void add_edge(int from, int to, int cap) {
//		edge e;
//		e.to = to, e.cap = cap, e.rev = G[to].size(), e.rcp = cap;
//		G[from].push_back(e);
//		e.to = from, e.cap = 0, e.rev = G[from].size() - 1, e.rcp = 0;
//		G[to].push_back(e);
//	}
//
//	int m(int a, int b){ return a < b ? a : b; }
//
//	int dfs(int v, int t, int f) {
//		if (v == t)return f;
//		used[v] = 1;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge &e = G[v][i];
//			if (!used[e.to] && e.cap > 0) {
//				int d = dfs(e.to, t, m(f, e.cap));
//				if (d > 0) {
//					e.cap -= d;
//					G[e.to][e.rev].cap += d;
//					return d;
//				}
//			}
//		}
//		return 0;
//	}
//
//	int ans(int s, int t) {
//		int flow = 0;
//		while (1) {
//			memset(used, 0, sizeof used);
//			int f = dfs(s, t, INT_MAX);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	int l = 0, r = 0;
//
//	int src[52], snk[52];
//
//	int goal = 0;
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &snk[i]);
//		goal += snk[i];
//		r = r < snk[i] ? snk[i] : r;
//	}
//	for (int i = 1; i <= n; i++)scanf("%d", &src[i]);
//
//	int limit;
//
//	bool flag = false;
//
//	int ans = INT_MAX;
//	int ans2[52][52];
//
//	while (l <= r){
//		limit = (l + r) / 2;
//
//		MaxFlow maxflow;
//
//		for (int i = 1; i <= n; i++){
//			maxflow.add_edge(0, i, src[i]); // source
//			maxflow.add_edge(n*n + n + i, n*n + 2 * n + 1, snk[i]); // sink
//			for (int j = 1; j <= n; j++){
//				int x = n + n * (i - 1) + j;
//				// linkage
//				maxflow.add_edge(j, x, limit);
//				maxflow.add_edge(x, n*n + n + i, limit);
//			}
//		}
//
//		int cmp = maxflow.ans(0, n*n + 2 * n + 1);
//		if (cmp >= goal){
//			r = limit - 1;
//			if (ans > limit){
//				ans = limit;
//				for (int i = 1; i <= n; i++){
//					for (int j = 0; j < maxflow.G[i].size(); j++){
//						edge a = maxflow.G[i][j];
//						if (a.to >= n + 1 && a.to <= n + n*n && a.rcp){
//							ans2[(a.to - n - 1) / n][(a.to - n - 1) % n] = a.rcp - a.cap;
//						}
//					}
//				}
//			}
//		}
//		else if (cmp < goal){
//			l = limit + 1;
//		}
//
//		flag = true;
//	}
//
//	printf("%d\n", ans);
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n-1; j++)printf("%d ", ans2[i][j]);
//		printf("%d\n", ans2[i][n-1]);
//	}
//}

//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//struct edge { int to, cap, rev, flow; };
//class MaxFlow{
//public:
//	vector<edge> G[2603];
//	bool used[2603];
//
//	void add_edge(int from, int to, int cap, int flow = 0) {
//		edge e;
//		e.to = to, e.cap = cap, e.rev = G[to].size(), e.flow = flow;
//		G[from].push_back(e);
//		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
//		G[to].push_back(e);
//	}
//
//	int m(int a, int b){ return a < b ? a : b; }
//
//	int dfs(int v, int t, int f) {
//		if (v == t)return f;
//		used[v] = 1;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge &e = G[v][i];
//			int rem = e.cap - e.flow;
//			if (!used[e.to] && rem > 0) {
//				int d = dfs(e.to, t, m(f, rem));
//				if (d > 0) {
//					e.flow += d;
//					G[e.to][e.rev].flow -= d;
//					return d;
//				}
//			}
//		}
//		return 0;
//	}
//
//	int ans(int s, int t) {
//		int flow = 0;
//		while (1) {
//			memset(used, 0, sizeof used);
//			int f = dfs(s, t, INT_MAX);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	int l = 0, r = 0;
//
//	int src[52], snk[52];
//
//	int goal = 0;
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &snk[i]);
//		goal += snk[i];
//		r = r < snk[i] ? snk[i] : r;
//	}
//	for (int i = 1; i <= n; i++)scanf("%d", &src[i]);
//
//	int limit;
//
//	bool flag = false;
//
//	int ans = INT_MAX;
//	int ans2[52][52];
//
//	while (l <= r){
//		limit = (l + r) / 2;
//
//		MaxFlow maxflow;
//
//		for (int i = 1; i <= n; i++){
//			maxflow.add_edge(0, i, src[i]); // source
//			maxflow.add_edge(n*n + n + i, n*n + 2 * n + 1, snk[i]); // sink
//			for (int j = 1; j <= n; j++){
//				int x = n + n * (i - 1) + j;
//				// linkage
//				maxflow.add_edge(j, x, limit);
//				maxflow.add_edge(x, n*n + n + i, limit);
//			}
//		}
//
//		int cmp = maxflow.ans(0, n*n + 2 * n + 1);
//		if (cmp >= goal){
//			r = limit - 1;
//			if (ans > limit){
//				ans = limit;
//				for (int i = 1; i <= n; i++){
//					for (int j = 0; j < maxflow.G[i].size(); j++){
//						edge a = maxflow.G[i][j];
//						if (a.to >= n + 1 && a.to <= n + n*n && a.flow >= 0){
//							ans2[(a.to - n - 1) / n][(a.to - n - 1) % n] = a.flow;
//						}
//					}
//				}
//			}
//		}
//		else if (cmp < goal){
//			l = limit + 1;
//		}
//
//		flag = true;
//	}
//
//	printf("%d\n", ans);
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n - 1; j++)printf("%d ", ans2[i][j]);
//		printf("%d\n", ans2[i][n - 1]);
//	}
//}