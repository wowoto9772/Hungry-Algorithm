#include <stdio.h>
#include <memory.h>
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

	void Init(int _n) {
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

	void FindMinCutComponent(int c) { // *optional
		vst[c] = true;
		for (int i = 0; i < graph[c].size(); i++) {
			int n = graph[c][i].next;
			if (graph[c][i].res && !vst[n]) {
				FindMinCutComponent(n);
			} // vst[i] && !vst[n + i] >> min cut component
		}
	}

};

int e[103][103];
int f[103][103][2];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &e[i][j]);
		}
	}

	MaxFlowDinic mf;

	int x = 0;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (f[i][j][0])continue;
			if (!e[i][j]) {
				++x;
				for (int k = j; k <= c; k++) {
					if (e[i][k] == 2)break;
					f[i][k][0] = x;
				}
			}
		}
	}

	int y = x;
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			if (f[j][i][1])continue;
			if (!e[j][i]) {
				++y;
				for (int k = j; k <= r; k++) {
					if (e[k][i] == 2)break;
					f[k][i][1] = y;
				}
			}
		}
	}

	mf.Init(y + 2);

	int src = 0, snk = y + 1;

	for (int i = 1; i <= x; i++)mf.AddEdge(src, i, 1);
	for (int i = x + 1; i <= y; i++)mf.AddEdge(i, snk, 1);

	map < int, map<int, bool> > chk;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!e[i][j]) {
				int a = f[i][j][0], b = f[i][j][1];
				if (chk[a][b])continue;
				chk[a][b] = true;
				mf.AddEdge(a, b, 1);
			}
		}
	}

	printf("%d\n", mf.Solve(src, snk));

}


/*
	3 3
	0 2 0
	2 0 2
	0 2 0
*/