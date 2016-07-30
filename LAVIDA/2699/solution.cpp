#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct MaxFlowDinic // V^2 * E
{
	typedef long long flow_t;

	struct Edge
	{
		int next;
		int inv; /* inverse edge index */
		flow_t res; /* residual */
	};

	int n;
	vector<vector<Edge>> graph;

	vector<unsigned> q, l, start;

	vector <bool> vst; // *optional

	void Init(int _n){
		n = _n;
		graph.resize(n);
		vst.resize(n); // *optional
		for (int i = 0; i < n; i++) graph[i].clear();
	}
	void AddNodes(int count) {
		n += count;
		graph.resize(n);
	}
	void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
		Edge forward = { e, graph[e].size(), cap };
		Edge reverse = { s, graph[s].size(), caprev };
		graph[s].push_back(forward);
		graph[e].push_back(reverse);
	}

	bool AssignLevel(int source, int sink) {
		int t = 0;
		memset(&l[0], 0, sizeof(l[0]) * l.size());
		l[source] = 1;
		q[t++] = source;
		for (int h = 0; h < t && !l[sink]; h++) {
			int cur = q[h];
			for (unsigned i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i].next;
				if (l[next]) continue;
				if (graph[cur][i].res > 0) {
					l[next] = l[cur] + 1;
					q[t++] = next;
				}
			}
		}
		return l[sink] != 0;
	}

	flow_t BlockFlow(int cur, int sink, flow_t currentFlow) {
		if (cur == sink) return currentFlow;
		for (unsigned &i = start[cur]; i < graph[cur].size(); i++) {
			int next = graph[cur][i].next;
			if (graph[cur][i].res == 0 || l[next] != l[cur] + 1)
				continue;
			if (flow_t res = BlockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
				int inv = graph[cur][i].inv;
				graph[cur][i].res -= res;
				graph[next][inv].res += res;
				return res;
			}
		}
		return 0;
	}

	flow_t Solve(int source, int sink)
	{
		q.resize(n);
		l.resize(n);
		start.resize(n);
		flow_t ans = 0;
		while (AssignLevel(source, sink)) {
			memset(&start[0], 0, sizeof(start[0])*n);
			while (flow_t flow = BlockFlow(source, sink, numeric_limits<flow_t>::max())) {
				ans += flow;
			}
		}
		return ans;
	}

};

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
		graph[v].push_back(u);
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

char str[103][103];
int ans[103];

int main(){
	map <char, int> par;

	for (int i = 'a'; i <= 'z'; i++)par[i] = i - 'a' + 1;

	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str[0]);

		int s = strlen(str[0]);

		int c['z' + 5] = { 0 };
		for (int i = 0; i < s; i++){
			c[str[0][i]]++;
		}

		MaxFlowDinic mf;
		mf.Init(2 * s + 2);

		for (int i = 'a'; i <= 'z'; i++){
			if (c[i]){
				mf.AddEdge(0, par[i], c[i]);
			}
		}

		for (int i = 1; i <= s; i++){
			scanf("%s", str[i]);

			int x = strlen(str[i]);
			for (int j = 0; j < x; j++){
				mf.AddEdge(par[str[i][j]], s + i, 1);
			}
		}

		for (int i = s + 1; i <= 2 * s; i++){
			mf.AddEdge(i, 2 * s + 1, 1);
		}

		int flg = mf.Solve(0, 2 * s + 1);

		if (flg == s){
			for (int i = s + 1; i <= 2 * s; i++){
				for (int j = 0; j < mf.graph[i].size(); j++){
					if (mf.graph[i][j].next <= s && mf.graph[i][j].res){
						ans[i - 1 - s] = mf.graph[i][j].next;
						break;
					}
				}
			}

			for (int j = 0; j < s; j++)printf("%c", 'a' - 1 + ans[j]);
			printf("\n");
		}
		else{
			printf("NO SOLUTION\n");
		}
	}
}

/*
	Network Flow + Greedy?
*/