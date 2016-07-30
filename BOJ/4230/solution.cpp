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

char wi[5], hu[5];

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) == 2){
		if (!n && !m)break;

		TwoSat sat;
		sat.init(n);

		for (int i = 1; i <= m; i++){
			scanf("%s %s", wi, hu);

			int w = wi[0] - '0';
			if (wi[1] == 'h')w = sat.negation(w);
			int h = hu[0] - '0';
			if (hu[1] == 'h')h = sat.negation(h);

			sat.addCNF(w, h);
			sat.addCNF(h, w);
		}

		vector <bool> ans = sat.solve();

		if (n > 0 && ans.empty()){
			printf("bad luck\n");
		}
		else{
			for (int i = 1; i < ans.size(); i++){
				if (i > 1)printf(" ");
				printf("%d", i);
				printf("%c", ans[i] ? 'h' : 'w');
			}printf("\n");
		}
	}
}