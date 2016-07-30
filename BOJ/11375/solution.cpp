//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//struct BipartiteMatching{
//	int V;
//	vector < vector <int> > G;
//	vector <int> match; // matching pair
//	vector <bool> used;
//
//	void init(int a){
//		V = a;
//		match.resize(V);
//		used.resize(V);
//		G.resize(V);
//		V--;
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
//	int ans() {
//		int res = 0;
//		for (int i = 0; i < match.size(); i++)match[i] = -1;
//		for (int v = 1; v <= V; v++) {
//			if (match[v] < 0) {
//				for (int i = 0; i < used.size(); i++)used[i] = false;
//				if (dfs(v)){
//					res++;
//				}
//			}
//		}
//		return res;
//	}
//};
//
//
//int main(){
//
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	BipartiteMatching btm;
//
//	btm.init(n + m + 1);
//
//	for (int i = 1; i <= n; i++){
//
//		int a;
//		scanf("%d", &a);
//
//		for (int j = 1; j <= a; j++){
//			int x;
//			scanf("%d", &x);
//
//			btm.add_edge(i, n + x);
//		}
//
//	}
//
//	printf("%d\n", btm.ans());
//
//}

#include <stdio.h>
#include <vector>

using namespace std;

struct HopcroftKarp // E * log V
{

	int n, m;
	vector<vector<int>> graph;
	vector<int> match, matched, depth, q, v;
	int vcnt;

	void init(int n_, int m_){
		n = n_, m = m_;
		graph.resize(n), match.resize(n), matched.resize(m), depth.resize(n), q.resize(n), v.resize(n);
	}


	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}

	bool BFS(){
		int t = 0;
		for (int i = 0; i < n; i++)
			if (match[i] == -1) depth[i] = 0, q[t++] = i;
			else depth[i] = -1;
			for (int h = 0; h < t; h++) {
				int cur = q[h];
				int curDepth = depth[cur];
				for (int i = 0; i < graph[cur].size(); i++) {
					int adj = graph[cur][i];
					if (matched[adj] == -1)
						return true;
					int next = matched[adj];
					if (depth[next] != -1) continue;
					depth[next] = curDepth + 1, q[t++] = next;
				}
			}
			return false;
	}

	bool DFS(int nod) {
		v[nod] = vcnt;
		for (int i = 0; i < graph[nod].size(); i++) {
			int adj = graph[nod][i];
			int next = matched[adj];
			if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
				continue;
			if (next == -1 || DFS(next)) {
				match[nod] = adj;
				matched[adj] = nod;
				return true;
			}
		}
		return false;
	}

	int Match()
	{
		fill(match.begin(), match.end(), -1);
		fill(matched.begin(), matched.end(), -1);
		int ans = 0;
		while (BFS()) {
			++vcnt;
			for (int i = 0; i < n; i++) if (depth[i] == 0 && DFS(i)) ans++;
		}
		return ans;
	}
};


int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	HopcroftKarp btm;
	 
	btm.init(n, m);

	for (int i = 0; i < n; i++){

		int a;
		scanf("%d", &a);

		for (int j = 1; j <= a; j++){
			int x;
			scanf("%d", &x);

			btm.add_edge(i, x - 1);
		}

	}

	printf("%d\n", btm.Match());
}