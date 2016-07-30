#include <stdio.h>
#include <memory.h>

#include <vector>
#include <map>

#define min(a, b) (a<b?a:b)

using namespace std;

#define node 1003

class AnotherMaxFlow{
public:
	struct edge { int to, cap, rev; };
	vector<edge> G[node];
	bool used[node];

	void add_edge(int from, int to, int cap) {
		edge e;
		e.to = to, e.cap = cap, e.rev = G[to].size();
		G[from].push_back(e);
		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
		G[to].push_back(e);
	}

	int dfs(int v, int t, int f) {
		if (v == t)return f;
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
			memset(used, 0, sizeof used);
			int f = dfs(s, t, 987654321);
			if (f == 0)return flow;
			flow += f;
		}
		return flow;
	}
};

int x[10005], y[10005];

int main(){
	int n, k;
	scanf("%d %d", &k, &n);

	AnotherMaxFlow graph;

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}

	for (int i = 1; i <= k; i++){
		graph.add_edge(0, i, 1); // link to source
		graph.add_edge(k + i, k * 2 + 1, 1); // link to sink
	}

	for (int i = 1; i <= n; i++){
		graph.add_edge(x[i], k + y[i], 1);
	}

	int flg = graph.max_flow(0, 2 * k + 1);

	printf("%d\n", flg);
}

//#include <stdio.h>
//#include <memory.h>
//
//#include <vector>
//#include <map>
//
//#define min(a, b) (a<b?a:b)
//
//using namespace std;
//
//#define node 1003
//
//class AnotherMaxFlow{
//public:
//	struct edge { int to, cap, rev; };
//	vector<edge> G[node];
//	bool used[node];
//
//	void add_edge(int from, int to, int cap) {
//		edge e;
//		e.to = to, e.cap = cap, e.rev = G[to].size();
//		G[from].push_back(e);
//		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
//		G[to].push_back(e);
//	}
//
//	int dfs(int v, int t, int f) {
//		if (v == t)return f;
//		used[v] = 1;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge &e = G[v][i];
//			if (!used[e.to] && e.cap > 0) {
//				int d = dfs(e.to, t, min(f, e.cap));
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
//	int max_flow(int s, int t) {
//		int flow = 0;
//		while (1) {
//			memset(used, 0, sizeof used);
//			int f = dfs(s, t, 987654321);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//class BipartiteMatching{
//public:
//	int V;
//	vector<int> G[node];
//	int match[node]; // matching pair
//	bool used[node];
//
//	BipartiteMatching(int a){
//		V = a;
//	}
//
//	void add_edge(int u, int v) {
//		G[u].push_back(v);
//		G[v].push_back(u);
//	}
//
//	bool dfs(int v) {
//		used[v] = 1;
//		for (int i = 0; i<G[v].size(); i++) {
//			int u = G[v][i], w = match[u];
//			if (w < 0 || !used[w] && dfs(w)) {
//				match[v] = u;
//				match[u] = v;
//				return 1;
//			}
//		}
//		return 0;
//	}
//
//	int BTM() {
//		int res = 0;
//		memset(match, -1, sizeof match);
//		for (int v = 1; v <= V; v++) {
//			if (match[v] < 0) {
//				memset(used, 0, sizeof(used));
//				if (dfs(v)){
//					res++;
//				}
//			}
//		}
//		return res;
//	}
//};
//
//int main(){
//	int n, k;
//	scanf("%d %d", &k, &n);
//
//	BipartiteMatching graph(2*k+1);
//	for (int i = 1; i <= n; i++){
//		int x, y;
//		scanf("%d %d", &x, &y);
//		graph.add_edge(x, k+y);
//	}
//
//	int flg = graph.BTM();
//
//	printf("%d\n", flg);
//}