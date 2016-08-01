#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <vector>
#include <algorithm>

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

char str[103][103];

#define node(i,j) ((i-1)*c+j)
#define upnode(i,j) (r*c+node(i,j))
#define src 0
#define snk (((r*c)<<1)|1)

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main() {

	int r, c;
	scanf("%d %d", &r, &c);

	MaxFlowDinic mf;
	mf.Init(((r*c) << 1) + 2);

	for (int i = 1; i <= r; i++) {
		scanf("%s", str[i] + 1);

		for (int j = 1; j <= c; j++) {

			if (str[i][j] == '#')continue;

			if (str[i][j] == 'K') {
				mf.AddEdge(src, node(i, j), INT_MAX);
				mf.AddEdge(node(i, j), upnode(i, j), INT_MAX);
			}
			else if (str[i][j] == 'H') {
				mf.AddEdge(upnode(i, j), snk, INT_MAX);
				mf.AddEdge(node(i, j), upnode(i, j), INT_MAX);
			}
			else
				mf.AddEdge(node(i, j), upnode(i, j), 1);
			
		}

	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (str[i][j] == '#')continue;
			for (int k = 0; k < 4; k++) {
				int ni = i + dr[k], nj = j + dc[k];
				if (ni < 1 || nj < 1 || ni > r || nj > c)continue;
				if (str[ni][nj] == '#')continue;
				mf.AddEdge(upnode(i, j), node(ni, nj), INT_MAX);
			}
		}
	}

	int flag = mf.Solve(src, snk);

	if (flag == INT_MAX)flag = -1;

	printf("%d\n", flag);

}