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
//int x[10005], y[10005];
//
//int main(){
//	int n;
//	scanf("%d", &n);
//
//	AnotherMaxFlow graph;
//
//	for (int i = 1; i <= n; i++){
//		scanf("%d %d", &x[i], &y[i]);
//	} 
//	
//	for (int i = 1; i <= 500; i++){
//		graph.add_edge(0, i, 1); // link to source
//		graph.add_edge(500 + i, 1000 + 1, 1); // link to sink
//	}// No single line must be drawn twice
//
//	for (int i = 1; i <= n; i++){
//		graph.add_edge(x[i], 500 + y[i], 1);
//	}
//
//	int flg = graph.max_flow(0, 1000 + 1);
//	if (flg % 2)printf("Mirko\n");
//	else{
//		printf("Slavko\n");
//	}
//}

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

class BipartiteMatching{
public:
	int V;
	vector<int> G[node];
	int match[node]; // matching pair
	bool used[node];

	BipartiteMatching(int a){
		V = a;
	}

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = 1;
		for (int i = 0; i<G[v].size(); i++) {
			int u = G[v][i], w = match[u];
			if (w < 0 || !used[w] && dfs(w)) {
				match[v] = u;
				match[u] = v;
				return 1;
			}
		}
		return 0;
	}

	int BTM() {
		int res = 0;
		memset(match, -1, sizeof match);
		for (int v = 1; v <= V; v++) {
			if (match[v] < 0) {
				memset(used, 0, sizeof(used));
				if (dfs(v)){
					res++;
				}
			}
		}
		return res;
	}
};

int x[10005], y[10005];

int main(){
	int n;
	scanf("%d", &n);

	BipartiteMatching graph(1001);

	for (int i = 1; i <= n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph.add_edge(x, 500 + y);
	}

	int flg = graph.BTM();
	if (flg % 2)printf("Mirko\n");
	else{
		printf("Slavko\n");
	}
}