#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

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
	scanf("%d %d", &n, &m);

	TwoSat sat;
	sat.init(m);

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		int ga = abs(a), gb = abs(b);
		if (a < 0)ga = sat.negation(ga);
		if (b < 0)gb = sat.negation(gb);

		sat.addCNF(ga, gb);
	}

	vector <bool> ans = sat.solve();

	if (n > 0 && ans.empty()){
		printf("OTL\n");
	}
	else{
		printf("^_^\n");
	}
}