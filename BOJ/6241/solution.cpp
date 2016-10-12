#include <cstdio>
#include <limits>
#include <limits.h>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

// from https://github.com/kcm1700/algorithms
// usage:
// MaxFlowDinic::Init(n);
// MaxFlowDinic::AddEdge(0, 1, 100, 100); // for bidirectional edge
// MaxFlowDinic::AddEdge(1, 2, 100); // directional edge
// result = MaxFlowDinic::Solve(0, 2); // source -> sink
// graph[i][edgeIndex].res -> residual
//
// in order to find out the minimum cut, use `l'.
// if l[i] == 0, i is unrechable.

struct MaxFlowDinic
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

	void Init(int _n){
		n = _n;
		graph.resize(n);
		for(int i = 0; i < n; i++) graph[i].clear();
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
		for(int h = 0; h < t && !l[sink]; h++) {
			int cur = q[h];
			for(unsigned i = 0; i < graph[cur].size(); i++) {
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
		for(unsigned &i = start[cur]; i < graph[cur].size(); i++) {
			int next = graph[cur][i].next;
			if (graph[cur][i].res == 0 || l[next] != l[cur]+1)
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
		while(AssignLevel(source,sink)) {
			memset(&start[0], 0, sizeof(start[0])*n);
			while(flow_t flow = BlockFlow(source,sink,numeric_limits<flow_t>::max())) {
				ans += flow;
			}
		}
		return ans;
	}
};

int pig[1003];

int main()
{

    int n, f, d;
    scanf("%d %d %d", &n, &f, &d);

    MaxFlowDinic mf;
    mf.Init(n+n+f+d+2);

    int src = 0, snk = n+n+f+d+1;

    for(int i=1; i<=f; i++)mf.AddEdge(src, i, 1);
    for(int i=1; i<=d; i++)mf.AddEdge(f+n+n+i, snk, 1);

    for(int i=1; i<=n; i++){
        int Fi, Di;
        scanf("%d %d", &Fi, &Di);
        mf.AddEdge(f+i, f+n+i, 1);
        for(int j=1; j<=Fi; j++){
            int _f;
            scanf("%d", &_f);
            mf.AddEdge(_f, f+i, 1);
        }
        for(int j=1; j<=Di; j++){
            int _d;
            scanf("%d", &_d);
            mf.AddEdge(f+n+i, f+n+n+_d, 1);
        }
    }

    printf("%d\n", mf.Solve(src, snk));

}
