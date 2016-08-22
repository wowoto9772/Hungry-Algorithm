#include <stdio.h>
#include <vector>
#include <queue>
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

	void Init(int _n) {
		n = _n;
		graph.resize(n);
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

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int r, c;
int e[505][505];
int cn[505];

int node(int a, int b) {
	return (a - 1)*c + b;
}

int upnode(int a, int b) {
	return r*c + node(a, b);
}

#define src 0
#define snk ((r*c)*2+1)

int main() {

	MaxFlowDinic mf;

	int x;

	scanf("%d %d %d", &r, &c, &x);

	mf.Init(snk + 3);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &e[i][j]);
			if (e[i][j] == -1)continue; // is not node
			mf.AddEdge(node(i, j), upnode(i, j), 1);
			if (e[i][j]) {
				cn[e[i][j]]++;
				if (cn[e[i][j]] == 1) {
					// src
					mf.AddEdge(src, node(i, j), 1);

					for (int k = 0; k < 4; k++) {
						int ni = i + dr[k];
						int nj = j + dc[k];
						if (ni < 1 || nj < 1 || ni > r || nj > c)continue;
						if (e[ni][nj] == -1)continue;

						if (e[ni][nj] == 0 || e[ni][nj] == e[i][j])
							mf.AddEdge(upnode(i, j), node(ni, nj), 1);
					}
				}
				else {
					// snk
					mf.AddEdge(upnode(i, j), snk, 1);
				}
			}
			else {
				for (int k = 0; k < 4; k++) {
					int ni = i + dr[k];
					int nj = j + dc[k];
					if (ni < 1 || nj < 1 || ni > r || nj > c)continue;
					if (e[ni][nj] == -1)continue;
					mf.AddEdge(upnode(i, j), node(ni, nj), 1);
				}
			}


		}
	}

	printf("%d\n", mf.Solve(src, snk) == x);

}

/*

// network flow
7 7 7
1 0 0 0 -1 0 2
0 0 3 0 0 0 4
1 0 0 0 5 0 0
2 0 -1 0 6 0 4
-1 0 0 0 6 0 0
0 0 7 0 0 7 0
3 5 0 0 0 0 0
*/
