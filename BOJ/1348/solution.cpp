#include <stdio.h>
#include <memory.h>

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
int C[103], P[103], ct, pt;

int d[2503][2503];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= c; j++){
			if (str[i][j] == 'C'){
				C[++ct] = (i - 1)*c + j;
			}
			else if (str[i][j] == 'P'){
				P[++pt] = (i - 1)*c + j;
			}
		}
	}

	memset(d, 0x2f, sizeof(d));

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			if (str[i][j] == 'C'){
				int cur = (i - 1)*c + j;

				queue <int> X, Y, C;
				X.push(i), Y.push(j), C.push(0);
				bool chk[53][53] = { 0 };
				chk[i][j] = true;

				while (!X.empty()){
					int xf = X.front(), yf = Y.front(), cf = C.front();
					X.pop(), Y.pop(), C.pop();
					if (str[xf][yf] == 'P'){
						int nxt = (xf - 1)*c + yf;
						if (d[cur][nxt] > cf)d[cur][nxt] = cf;
					}
					cf++;
					for (int k = 0; k < 4; k++){
						int nx = dr[k] + xf, ny = dc[k] + yf;
						if (nx < 1 || nx > r || ny < 1 || ny > c)continue;
						if (str[nx][ny] != 'X' && !chk[nx][ny]){
							chk[nx][ny] = true;
							X.push(nx), Y.push(ny), C.push(cf);
						}
					}
				}
			}
		}
	}

	for (int limit = 0; limit <= r*c; limit++){
		MaxFlowDinic mf;
		mf.Init(pt + ct + 2);

		for (int i = 1; i <= ct; i++){
			mf.AddEdge(0, i, 1); // source
			for (int j = 1; j <= pt; j++){
				if (d[C[i]][P[j]] <= limit){ // validate
					mf.AddEdge(i, ct + j, 1);
				}
			}
		}

		for (int i = 1; i <= pt; i++){
			mf.AddEdge(ct + i, pt + ct + 1, 1); // sink
		}

		if (mf.Solve(0, pt + ct + 1) == ct){
			printf("%d\n", limit);
			return 0;
		}
	}

	printf("-1\n");

}