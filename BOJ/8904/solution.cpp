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

int le[103], work[103], ri[103];

#define src 0
#define m 500
#define snk n+m+1

int main() {

	int tc;
	scanf("%d", &tc);

	while (tc--) {

		int k, n;
		scanf("%d %d", &k, &n);

		MaxFlowDinic mf;
		mf.Init(snk + 1);

		int flg = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &le[i], &work[i], &ri[i]);
			mf.AddEdge(m + i, snk, work[i]); // for furniture
			flg += work[i];
		}

		for (int t = 1; t < 500; t++) {

			int cur = 0;

			for (int i = 1; i <= n; i++) {
				if (le[i] <= t && t < ri[i]) {
					mf.AddEdge(t, m + i, 1); // for work
					cur++;
				}
			}

			mf.AddEdge(src, t, min(cur, k)); // for blacksmith

		}

		flg -= mf.Solve(src, snk);

		if (flg)printf("0\n");
		else {
			flg = 1;

			vector < vector <int> > out;
			out.resize(n + 1);

			for (int i = 0; i < mf.graph[src].size(); i++) {
				int nxt = mf.graph[src][i].next; // time
				int r = mf.graph[src][i].inv;
				if (mf.graph[nxt][r].res > 0) { // going to work during this term
					for (int j = 0; j < mf.graph[nxt].size(); j++) {
						int nxt2 = mf.graph[nxt][j].next;
						if (nxt2 <= m)continue; // only furniture

						int r2 = mf.graph[nxt][j].inv;
						if (mf.graph[nxt2][r2].res > 0) {
							out[nxt2 - m].push_back(nxt);
						}
					}
				}
			}

			for (int i = 1; i <= n; i++)sort(out[i].begin(), out[i].end());

			for (int i = 1; i <= n; i++) {

				vector <int> pars;
				int p = -1;
				int k = 1;

				for (int j = 0; j < out[i].size(); j++) {
					if (p + k == out[i][j]) {
						k++;
					}
					else {
						if (p != -1) {
							pars.push_back(pars.back() + k);
							k = 1;
						}
						pars.push_back(out[i][j]);
						p = out[i][j];
					}
				}

				pars.push_back(pars.back() + k);

				printf("%d", pars.size() / 2);

				for (int j = 0; j < pars.size(); j += 2) {
					printf(" %d %d", pars[j], pars[j + 1]);
				}
				printf("\n");
			}

		}

	}
}

//#include <stdio.h>
//#include <vector>
//#include <queue>
//#include <functional>
//
//using namespace std;
//
//int rem[103];
//int le[103], ri[103];
//
//int main() {
//
//	int tc;
//	scanf("%d", &tc);
//
//	while (tc--) {
//
//		int k, n;
//		scanf("%d %d", &k, &n);
//
//		vector < vector < int > > out;
//		out.resize(n + 1);
//
//		for (int i = 1; i <= n; i++) {
//
//			scanf("%d %d %d", &le[i], &rem[i], &ri[i]);
//
//		}
//
//		int ans = 1;
//
//		for (int t = 1; t < 500; t++) {
//
//			priority_queue < pair <int, int>, vector < pair< int, int> >, greater < pair <int, int> > > work;
//
//			for (int i = 1; i <= n; i++) {
//				if (!rem[i])continue;
//				if (ri[i] <= t || t < le[i])continue;
//				work.push(make_pair((ri[i] - t) - rem[i], i));
//			}
//
//			for (int j = 1; j <= k && !work.empty(); j++) {
//				rem[work.top().second]--;
//				out[work.top().second].push_back(t);
//				work.pop();
//			}
//
//		}
//
//		for (int i = 1; ans && i <= n; i++) {
//			if (rem[i])ans = 0;
//		}
//
//		if(!ans)printf("%d\n", ans);
//		else {
//			for (int i = 1; i <= n; i++) {
//
//				vector <int> pars;
//				int p = -1;
//				int k = 1;
//
//				for (int j = 0; j < out[i].size(); j++) {
//					if (p + k == out[i][j]) {
//						k++;
//					}
//					else {
//						if (p != -1) {
//							pars.push_back(pars.back() + k);
//							k = 1;
//						}
//						pars.push_back(out[i][j]);
//						p = out[i][j];
//					}
//				}
//				
//				pars.push_back(pars.back() + k);
//
//				printf("%d", pars.size() / 2);
//
//				for (int j = 0; j < pars.size(); j += 2) {
//					printf(" %d %d", pars[j], pars[j + 1]);
//				}
//				printf("\n");
//			}
//		}
//
//	}
//
//}	// FAIL