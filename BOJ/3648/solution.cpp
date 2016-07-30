//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct MaxFlowDinik{ // V^2 * E
//	struct edge { int to, cap, rev; };
//	vector < vector <edge> > G;
//	vector <bool> used;
//
//	void init(int n){
//		G.resize(n);
//		used.resize(n);
//	}
//
//	void add_edge(int from_, int to_, int cap_) {
//		edge e;
//		e.to = to_, e.cap = cap_, e.rev = G[to_].size();
//		G[from_].push_back(e);
//		e.to = from_, e.cap = 0, e.rev = G[from_].size() - 1;
//		G[to_].push_back(e);
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
//			for (int i = 0; i < used.size(); i++)used[i] = false;
//			int f = dfs(s, t, 987654321);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//int main(){
//	int n, m;
//	while (scanf("%d %d", &n, &m) == 2){
//
//		MaxFlowDinik mf;
//		mf.init(n * 3 + m + 2);
//
//		for (int i = 1; i <= n; i++){
//			mf.add_edge(0, i, 1); // link to source
//			mf.add_edge(i, n + i, 1); // AC
//			if(i > 1)mf.add_edge(i, 2 * n + i, 1); // WA
//		}
//
//		for (int i = 1; i <= m; i++){
//			mf.add_edge(3 * n + i, 3 * n + m + 1, 1); // link to sink
//
//			int a, b;
//			scanf("%d %d", &a, &b);
//
//			int ga = abs(a), gb = abs(b);
//			int ad = n;
//			if (a < 0)ad = 2 * n;
//			if (ga == 1){
//				if (a > 0){
//					mf.add_edge(ad + ga, 3 * n + i, 1);
//				}
//			}
//			else{
//				mf.add_edge(ad + ga, 3 * n + i, 1);
//			}
//
//			ad = n;
//			if (b < 0)ad = 2 * n;
//			if (gb == 1){
//				if (b > 0){
//					mf.add_edge(ad + gb, 3 * n + i, 1);
//				}
//			}
//			else{
//				mf.add_edge(ad + gb, 3 * n + i, 1);
//			}
//		}
//
//		int flg = mf.max_flow(0, 3 * n + m + 1);
//
//		if (flg == m)printf("yes\n");
//		else{
//			printf("no\n");
//		}
//	}
//}

#include <algorithm>
#include <vector>

using namespace std;

// usage
// TwoSat ts;
// ts.init(n);
// for(each implication) ts.add(p,q); (both p => q and ~q => ~p are added)
// for(each implication) ts.add(p+n,q); (both ~p => q and ~q => p are added)
// for(each implication) ts.add(p,q+n); (both p => ~q and q => ~p are added)
// ts.negation(p) => p+n
// ts.negation(p+n) => p
//
// vector<bool> result = ts.solve();
// if (n > 0 && result.empty()): NOT satisfiable. ***n > 0*** check is IMPORTANT
// if (result[p] == true): variable p is true
// if (result[p] == false): variable p is false
//
// caution: n != TwoSat.n

struct TwoSat
{
	int n;
	int var;
	vector<vector<int>> graph;
	vector<vector<int>> grev;

	int vcnt;
	vector<int> v;

	void init(int var_) {
		var = var_;
		n = var_ * 2;
		graph.clear(); graph.resize(n);
		grev.clear(); grev.resize(n);

		vcnt = 0;
		v.clear(); v.resize(n);
	}

	int negation(int nod) {
		return nod >= var ? nod - var : nod + var;
	}

	// p implies q. p -> q
	void add(int p, int q) {
		graph[p].push_back(q);
		graph[negation(q)].push_back(negation(p));
		grev[q].push_back(p);
		grev[negation(p)].push_back(negation(q));
	}

	// and (p or q)
	void addCNF(int p, int q) {
		add(negation(p), q);
	}

	vector<int> emit;
	void dfs(int nod, vector<vector<int>> &graph) {
		v[nod] = vcnt;
		for (int next : graph[nod]){
			if (v[next] == vcnt) continue;
			dfs(next, graph);
		}
		emit.push_back(nod);
	}

	vector<bool> solve() {
		vector<bool> solution(var);
		vector<int> scc_check(n);
		int scc_index = 0;

		++vcnt;
		emit.clear();
		for (int i = 0; i < n; i++) {
			if (v[i] == vcnt) continue;
			dfs(i, graph);
		}

		++vcnt;
		for (auto start : vector<int>(emit.rbegin(), emit.rend())) {
			if (v[start] == vcnt) continue;
			emit.clear();
			dfs(start, grev);
			++scc_index;
			for (auto node : emit) {
				scc_check[node] = scc_index;
				if (scc_check[negation(node)] == scc_index) {
					// contradiction found
					solution.clear();
					return solution;
				}
				solution[node >= var ? node - var : node] = (node < var);
			}
		}

		return solution;
	}
};

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) == 2){

		TwoSat sat;
		sat.init(n + 1);

		bool say = false;

		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			if (a == 1 || b == 1){
				continue;
			}
			else if (a == -1){
				a = b;
			}
			else if (b == -1){
				b = a;
			}

			int ga = abs(a), gb = abs(b);

			if (a < 0)ga = sat.negation(ga);
			if (b < 0)gb = sat.negation(gb);

			sat.addCNF(ga, gb);
		}

		vector <bool> ans = sat.solve();

		if (n > 0 && ans.empty()){
			printf("no\n");
		}
		else{
			printf("yes\n");
		}
	}
}