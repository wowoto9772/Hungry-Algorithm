#include <stdio.h>

#include <limits.h>

#include <limits>

#include <string.h>

#include <string>

#include <memory.h>

#include <vector>

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
	vector < vector <Edge> > graph;

	vector <unsigned> q, l, start;

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

	void FindMinCutComponent(int c){ // *optional
		vst[c] = true;
		for (int i = 0; i < graph[c].size(); i++){
			int n = graph[c][i].next;
			if (graph[c][i].res && !vst[n]){
				FindMinCutComponent(n);
			} // vst[i] && !vst[n + i] >> min cut component
		}
	}

};

char str[123];

#define src (0)
#define snk (s+2*t+1)

bool source[603], sink[603];

int main(){

	int s, r, f, t;
	scanf("%d %d %d %d", &s, &r, &f, &t);

	MaxFlowDinic mf;

	mf.Init(s+2+t*2);

	map <string, int> mp;

	int top = 0;

	for(int i=0; i<r; i++){

		scanf("%s", str);

		string tmp = string(str);

		if(!mp[tmp]){

			mp[tmp] = ++top;

			source[top] = true;

			mf.AddEdge(src, top, 1);

		}

	}

	for(int i=0; i<f; i++){

		scanf("%s", str);

		string tmp = string(str);

		if(!mp[tmp]){
		
			mp[tmp] = ++top;

			sink[top] = true;

			mf.AddEdge(top, snk, 1);

		}

	}

	for(int i=1; i<=t; i++){

		int c;
		scanf("%d", &c);

		vector <int> e;

		for(int j=1; j<=c; j++){

			scanf("%s", str);

			string tmp = string(str);

			if(!mp[tmp])mp[tmp] = ++top;

			e.push_back(mp[tmp]);

		}

		mf.AddEdge(s+2*i-1, s+2*i, 1);

		for(auto &v : e){
			
			if(source[v]){
				mf.AddEdge(v, s+2*i-1, 1);
			}else if(sink[v]){
				mf.AddEdge(s+2*i, v, 1);
			}else{
				mf.AddEdge(v, s+2*i-1, 1);
				mf.AddEdge(s+2*i, v, 1);
			}

		}

	}

	printf("%d\n", mf.Solve(src, snk));

}
