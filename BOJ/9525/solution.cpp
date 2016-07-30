//#include <stdio.h>
//#include <limits.h>
//#include <memory.h>
//
//#include <vector>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//char str[103][103];
//bool chk[103][103][2];
//int id[103][103][2];
//int P[20003];
//
//vector < vector < int > > link;
//map < int, map <int, int> > cap, flow;
//
//int m(int a, int b){ return a < b ? a : b; }
//
//int MaximumFlow(int source, int sink){ // fordFulkerson
//
//	int ret = 0;
//
//	while (true){
//		queue <int> Q;
//
//		memset(P, 0xff, sizeof(P));
//		P[source] = source; // argument path
//		Q.push(source);
//
//		while (!Q.empty() && P[sink] == -1){
//			int now = Q.front(); Q.pop();
//
//			for (int i = 0; i < link[now].size(); i++){
//				int nxt = link[now][i];
//				if (cap[now][nxt] - flow[now][nxt] > 0 && P[nxt] == -1){
//					// amount to use
//					Q.push(nxt);
//					P[nxt] = now;
//				}
//			}
//		}
//
//		if (P[sink] == -1)break; // end condition
//
//		int amount = INT_MAX;
//
//		for (int p = sink; p != source; p = P[p]){
//			amount = m(amount, cap[P[p]][p] - flow[P[p]][p]);
//		}
//
//		for (int p = sink; p != source; p = P[p]){
//			flow[P[p]][p] += amount;
//			flow[p][P[p]] -= amount;
//		}
//
//		ret += amount;
//	}
//
//	return ret;
//}
//
//int main(){
//
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)scanf("%s", str[i]);
//
//	int top = 0;
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++){
//			if (str[i][j] == 'X')continue;
//			int ni = i, nj = j;
//			bool flag = false;
//			while (ni < n){
//				if (str[ni][nj] == 'X')break;
//				if (chk[ni][nj][0])break;
//				if (!flag){
//					++top;
//					flag = true;
//				}
//				chk[ni][nj][0] = true;
//				id[ni][nj][0] = top;
//				ni++;
//			}
//			ni = i;
//			flag = false;
//			while (nj < n){
//				if (str[ni][nj] == 'X')break;
//				if (chk[ni][nj][1])break;
//				if (!flag){
//					++top;
//					flag = true;
//				}
//				chk[ni][nj][1] = true;
//				id[ni][nj][1] = top;
//				nj++;
//			}
//		}
//	}
//
//	top++;
//	link.resize(top + 1);
//
//	map < int, map <int, bool> > chk;
//
//	bool src[20003] = { 0 }, snk[20003] = { 0 };
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++){
//			if (str[i][j] == 'X')continue;
//			if (id[i][j][0] && id[i][j][1]){
//				if (!src[id[i][j][0]]){
//					src[id[i][j][0]] = true;
//					link[0].push_back(id[i][j][0]);
//					// source
//					cap[0][id[i][j][0]] = 1;
//				}
//				if (!chk[id[i][j][0]][id[i][j][1]]){
//					chk[id[i][j][0]][id[i][j][1]] = true;
//					link[id[i][j][0]].push_back(id[i][j][1]); // forward
//					link[id[i][j][1]].push_back(id[i][j][0]); // backward
//					// linkage
//					cap[id[i][j][0]][id[i][j][1]] = 1; // forward
//				}
//				if (!snk[id[i][j][1]]){
//					snk[id[i][j][1]] = true;
//					link[id[i][j][1]].push_back(top);
//					// sink
//					cap[id[i][j][1]][top] = 1;
//				}
//			}
//		}
//	}
//
//	printf("%d\n", MaximumFlow(0, top));
//}

#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <vector>
#include <map>

using namespace std;

char str[103][103];
bool chk[103][103][2];
int id[103][103][2];

class MaxFlow{
public:
	struct edge { int to, cap, rev; };
	vector<edge> G[20003];
	bool used[20003];

	void add_edge(int from, int to, int cap) {
		edge e;
		e.to = to, e.cap = cap, e.rev = G[to].size();
		G[from].push_back(e);
		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
		G[to].push_back(e);
	}

	int m(int a, int b){ return a < b ? a : b; }

	int dfs(int v, int t, int f) {
		if (v == t)return f;
		used[v] = 1;
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, m(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int ans(int s, int t) {
		int flow = 0;
		while (1) {
			memset(used, 0, sizeof used);
			int f = dfs(s, t, INT_MAX);
			if (f == 0)return flow;
			flow += f;
		}
		return flow;
	}
};

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	int top = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (str[i][j] == 'X')continue;
			int ni = i, nj = j;
			bool flag = false;
			while (ni < n){
				if (str[ni][nj] == 'X')break;
				if (chk[ni][nj][0])break;
				if (!flag){
					++top;
					flag = true;
				}
				chk[ni][nj][0] = true;
				id[ni][nj][0] = top;
				ni++;
			}
			ni = i;
			flag = false;
			while (nj < n){
				if (str[ni][nj] == 'X')break;
				if (chk[ni][nj][1])break;
				if (!flag){
					++top;
					flag = true;
				}
				chk[ni][nj][1] = true;
				id[ni][nj][1] = top;
				nj++;
			}
		}
	}

	top++;
	link.resize(top + 1);

	map < int, map <int, bool> > chk;

	bool src[20003] = { 0 }, snk[20003] = { 0 };

	MaxFlow maxflow;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (str[i][j] == 'X')continue;
			if (id[i][j][0] && id[i][j][1]){
				if (!src[id[i][j][0]]){ // sink
					src[id[i][j][0]] = true;
					maxflow.add_edge(0, id[i][j][0], 1);
				} // linkage
				if (!chk[id[i][j][0]][id[i][j][1]]){
					chk[id[i][j][0]][id[i][j][1]] = true;
					maxflow.add_edge(id[i][j][0], id[i][j][1], 1);
				} // sink
				if (!snk[id[i][j][1]]){
					snk[id[i][j][1]] = true;
					maxflow.add_edge(id[i][j][1], top, 1);
				}
			}
		}
	}

	printf("%d\n", maxflow.ans(0, top));
}