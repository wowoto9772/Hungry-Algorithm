#include <stdio.h>
#include <memory.h>

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

char str[53][53];

int w[53][53];
int h[53][53];

#define src 0
#define snk top+1
#define inf top

int main(){

	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)scanf("%s", str[i]);

	int top = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (w[i][j] || str[i][j] == '.')continue;
			top++;
			for (int k = j; k < c; k++){
				if (str[i][k] == '.')break;
				if (!w[i][k])w[i][k] = top;
			}
		}
	}

	for (int i = 0; i < c; i++){
		for (int j = 0; j < r; j++){
			if (h[j][i] || str[j][i] == '.')continue;
			top++;
			for (int k = j; k < r; k++){
				if (str[k][i] == '.')break;
				if (!h[k][i])h[k][i] = top;
			}
		}
	}
	
	MaxFlowDinic mf;
	mf.Init(top + 2);

	bool chk[1234] = { 0 };
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (str[i][j] == '*'){
				mf.AddEdge(w[i][j], h[i][j], 1);
				if (!chk[w[i][j]]){
					mf.AddEdge(src, w[i][j], inf);
					chk[w[i][j]] = true;
				}
				if (!chk[h[i][j]]){
					mf.AddEdge(h[i][j], snk, inf);
					chk[h[i][j]] = true;
				}

			}
		}
	}

	printf("%d\n", mf.Solve(src, snk));

}

/*
2 3
*.*
***
*/


//#include <stdio.h>
//#include <memory.h>
//
//#include <vector>
//
//using namespace std;
//
//struct HopcroftKarp // E * log V
//{
//
//	int n, m;
//	vector<vector<int>> graph;
//	vector<int> match, matched, depth, q, v;
//	int vcnt;
//
//	void init(int n_, int m_){
//		n_++, m_++;
//		n = n_, m = m_;
//		graph.resize(n), match.resize(n), matched.resize(m), depth.resize(n), q.resize(n), v.resize(n);
//	}
//
//
//	void add_edge(int u, int v) {
//		graph[u].push_back(v);
//	}
//
//	bool BFS(){
//		int t = 0;
//		for (int i = 0; i < n; i++)
//			if (match[i] == -1) depth[i] = 0, q[t++] = i;
//			else depth[i] = -1;
//			for (int h = 0; h < t; h++) {
//				int cur = q[h];
//				int curDepth = depth[cur];
//				for (int i = 0; i < graph[cur].size(); i++) {
//					int adj = graph[cur][i];
//					if (matched[adj] == -1)
//						return true;
//					int next = matched[adj];
//					if (depth[next] != -1) continue;
//					depth[next] = curDepth + 1, q[t++] = next;
//				}
//			}
//			return false;
//	}
//
//	bool DFS(int nod) {
//		v[nod] = vcnt;
//		for (int i = 0; i < graph[nod].size(); i++) {
//			int adj = graph[nod][i];
//			int next = matched[adj];
//			if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
//				continue;
//			if (next == -1 || DFS(next)) {
//				match[nod] = adj;
//				matched[adj] = nod;
//				return true;
//			}
//		}
//		return false;
//	}
//
//	int Match()
//	{
//		fill(match.begin(), match.end(), -1);
//		fill(matched.begin(), matched.end(), -1);
//		int ans = 0;
//		while (BFS()) {
//			++vcnt;
//			for (int i = 0; i < n; i++) if (depth[i] == 0 && DFS(i)) ans++;
//		}
//		return ans;
//	}
//
//};
//
//
//char str[53][53];
//
//int w[53][53];
//int h[53][53];
//
//int main(){
//
//	int r, c;
//	scanf("%d %d", &r, &c);
//
//	for (int i = 0; i < r; i++)scanf("%s", str[i]);
//
//	memset(w, 0xff, sizeof(w));
//	memset(h, 0xff, sizeof(h));
//
//	int wtp = 0;
//	for (int i = 0; i < r; i++){
//		for (int j = 0; j < c; j++){
//			if (w[i][j] > -1 || str[i][j] == '.')continue;
//			for (int k = j; k < c; k++){
//				if (str[i][k] == '.')break;
//				w[i][k] = wtp;
//			}
//			wtp++;
//		}
//	}
//
//	int htp = 0;
//	for (int i = 0; i < c; i++){
//		for (int j = 0; j < r; j++){
//			if (h[j][i] > -1 || str[j][i] == '.')continue;
//			for (int k = j; k < r; k++){
//				if (str[k][i] == '.')break;
//				h[k][i] = htp;
//			}
//			htp++;
//		}
//	}
//
//	HopcroftKarp btm;
//	btm.init(wtp, htp);
//
//	for (int i = 0; i < r; i++){
//		for (int j = 0; j < c; j++){
//			if (str[i][j] == '*'){
//				btm.add_edge(w[i][j], h[i][j]);
//			}
//		}
//	}
//
//	printf("%d\n", btm.Match());
//}