#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

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

char str[53][53];

int main()
{

    int n;
    scanf("%d", &n);
    
    for(int i=0; i<=n; i++){
        scanf("%s", str[i]+1);
    }

    MaxFlowDinic mf;
    mf.Init(2*n+2);

    vector < vector <int> > hate;
    hate.resize(n+1);

    fo(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(str[i][j] == 'Y'){
                hate[i].push_back(j);
            }
        }
    }

    vector < int > color(n+1, -1);

    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            queue <int> q;
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int f = q.front();q.pop();
                for(int j=0; j<hate[f].size(); j++){
                    int g = hate[f][j];
                    if(color[g] == -1){
                        color[g] = !color[f];
                        q.push(g);
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(color[i] == 0){
            mf.AddEdge(0, i, 1);
            for(auto &e : hate[i]){
                if(color[e] == 1)mf.AddEdge(i, n+e, 1);
            }
        }else{
            mf.AddEdge(n+i, 2*n+1, 1);
        }
    }
    for(int i=1; i<=n; i++){
        if(color[i] == 1)mf.AddEdge(n+i, 2*n+1, 1);
    }

    printf("%d\n", n - mf.Solve(0, 2*n+1));

}