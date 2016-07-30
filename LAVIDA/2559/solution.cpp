//#include <stdio.h>
//#include <memory.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int m(int a, int b){ return a < b ? a : b; }
//
//class MaxFlow{
//public:
//	struct edge { int to, cap, rev; };
//	vector<edge> G[2603];
//	bool used[2603];
//
//	void add_edge(int from, int to, int cap) {
//		edge e;
//		e.to = to, e.cap = cap, e.rev = G[to].size();
//		G[from].push_back(e);
//		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
//		G[to].push_back(e);
//	}
//
//	int m(int a, int b){ return a < b ? a : b; }
//
//	int dfs(int v, int t, int f) {
//		if (v == t)return f;
//		used[v] = 1;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge &e = G[v][i];
//			if (!used[e.to] && e.cap > 0) {
//				int d = dfs(e.to, t, m(f, e.cap));
//				if (d > 0) {
//					e.cap -= d;
//					G[e.to][e.rev].cap += d;
//					return d;
//				}
//			}
//		}
//		return 0;
//	}
//
//	int ans(int s, int t) {
//		int flow = 0;
//		while (1) {
//			memset(used, 0, sizeof used);
//			int f = dfs(s, t, INT_MAX);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//int cap[550][550];
//int flow[550][550];
//int P[550];
//
//int type[103];
//int pos[103];
//
//int MaximumFlow(int source, int sink, int end){ // fordFulkerson
//
//	memset(flow, 0, sizeof(flow));
//
//	int ret = 0;
//
//	while (true){
//
//		queue <int> Q;
//
//		memset(P, 0xff, sizeof(P));
//		P[source] = source; // argument path
//		Q.push(source);
//
//		while (!Q.empty() && P[sink] == -1){
//			int now = Q.front(); Q.pop();
//
//			for (int i = 1; i <= end; i++){
//				int nxt = i;
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
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, d;
//		scanf("%d %d", &n, &d);
//
//		int ans = INT_MAX;
//
//		pos[0] = 0;
//		pos[n + 1] = d;
//		for (int i = 1; i <= n; i++){
//			char x;
//			int y;
//			scanf(" %c-%d", &x, &pos[i]);
//			if (x == 'W'){ // wood
//				type[i] = 0;
//			}
//			else if (x == 'T'){ // flying turtle
//				type[i] = 1;
//			}
//		}
//
//		int l = 1, r = d, ld;
//		while (l <= r){
//			ld = (l + r) / 2;
//			for (int i = 1; i <= n; i++){
//				if (pos[i] - pos[0] <= ld){ // source 1
//					cap[0][2 + i] = 1;
//				}
//				if (pos[n + 1] - pos[i] <= ld){ // sink 1
//					cap[2 + 4 * n + i][1] = 1;
//				}
//				if (type[i] == 0){ // wood
//					cap[2 + i][2 + 3 * n + i] = INT_MAX;
//					cap[2 + 3 * n + i][2 + 4 * n + i] = INT_MAX;
//					cap[2 + 2 * n + i][2 + 3 * n + i] = INT_MAX;
//				}
//				else{ // flying turtle
//					cap[2 + i][2 + 3 * n + i] = 1;
//					cap[2 + 3 * n + i][2 + 4 * n + i] = 1;
//					cap[2 + 2 * n + i][2 + 3 * n + i] = 1;
//				}
//				for (int j = i + 1; j <= n; j++){
//					if (pos[j] - pos[i] <= ld){
//						if (type[j] == 0){
//							cap[2 + 4 * n + i][j] = INT_MAX;
//						}
//						else{
//							cap[2 + 4 * n + i][j] = 1;
//						}
//					}
//					else{
//						break;
//					}
//				}
//			}
//			for (int i = n; i >= 1; i--){
//				if (pos[n + 1] - pos[i] <= ld){ // source 2
//					cap[1][2 + 2 * n + i] = 1;
//				}
//				if (pos[i] - pos[0] <= ld){ // sink2
//					cap[2 + 4 * n + i][2] = 1;
//				}
//				for (int j = i - 1; j >= 1; j--){
//					if (pos[i] - pos[j] <= ld){
//						if (type[j] == 0){
//							cap[2 + 4 * n + i][2 + 2 * n + j] = INT_MAX;
//						}
//						else{
//							cap[2 + 4 * n + i][2 + 2 * n + j] = 1;
//						}
//					}
//					else{
//						break;
//					}
//				}
//			}
//
//			int x = MaximumFlow(0, 2, 2 + 5 * n + 3);
//			if (x){
//				r = ld - 1;
//				ans = m(ans, ld);
//			}
//			else{
//				l = ld + 1;
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//}

//#include <stdio.h>
//#include <memory.h>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int m(int a, int b){ return a < b ? a : b; }
//
//class MaxFlow{
//public:
//	struct edge { int to, cap, rev; };
//	vector<edge> G[2603];
//	bool used[2603];
//
//	void add_edge(int from, int to, int cap) {
//		edge e;
//		e.to = to, e.cap = cap, e.rev = G[to].size();
//		G[from].push_back(e);
//		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
//		G[to].push_back(e);
//	}
//
//	int m(int a, int b){ return a < b ? a : b; }
//
//	int dfs(int v, int t, int f) {
//		if (v == t)return f;
//		used[v] = 1;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge &e = G[v][i];
//			if (!used[e.to] && e.cap > 0) {
//				int d = dfs(e.to, t, m(f, e.cap));
//				if (d > 0) {
//					e.cap -= d;
//					G[e.to][e.rev].cap += d;
//					return d;
//				}
//			}
//		}
//		return 0;
//	}
//
//	int ans(int s, int t) {
//		int flow = 0;
//		while (1) {
//			memset(used, 0, sizeof used);
//			int f = dfs(s, t, INT_MAX);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//int type[103];
//int pos[103];
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		int n, d;
//		scanf("%d %d", &n, &d);
//
//		pos[0] = 0;
//		pos[n + 1] = d;
//
//		MaxFlow flow;
//
//		for (int i = 1; i <= n; i++){
//			char x;
//			int y;
//			scanf(" %c-%d", &x, &pos[i]);
//			if (x == 'W'){ // wood
//				type[i] = 0;
//				flow.add_edge(i, n + i, INT_MAX);
//			}
//			else if (x == 'T'){ // flying turtle
//				type[i] = 1;
//				flow.add_edge(i, n + i, 1);
//			}
//		}
//
//		int l = 1, r = d, ld;
//		while (l <= r){
//			ld = (l + r) / 2;
//			for (int i = 1; i <= n; i++){
//				if (pos[i] - pos[0] <= ld){ // source 1
//					cap[0][i] = 1;
//				}
//				if (pos[n + 1] - pos[i] <= ld){ // sink 1
//					cap[i][2 * n + 1] = 1;
//				}
//				for (int j = i + 1; j <= n; j++){
//					if (pos[j] - pos[i] <= ld){
//						if (type[j] == 0){
//							cap[n + i][j] = INT_MAX;
//						}
//						else{
//							cap[n + i][j] = 1;
//						}
//					}
//				}
//			}
//			for (int i = n; i >= 1; i--){
//				if (pos[n + 1] - pos[i] <= ld){ // source 2
//					cap[2 * n + 1][3 * n + i] = 1;
//				}
//				if (pos[i] - pos[0] <= ld){ // sink2
//					cap[n + i][4 * n + 1] = 1;
//				}
//				for (int j = i + 1; j <= n; j++){
//					if (pos[j] - pos[i] <= ld){
//						if (type[j] == 0){
//							cap[2 * n + i][j] = INT_MAX;
//						}
//						else{
//							cap[2 * n + i][j] = 1;
//						}
//					}
//				}
//			}
//
//		}
//	}
//}

#include <stdio.h>
#include <memory.h>
#include <limits.h>

int m(int a, int b){ return a < b ? a : b; }
int type[103];
int pos[103];

bool chk[103];

bool good;
int n;

int A(int a){ return a < -a ? -a : a; }
bool cango(int c, int d, int ld){
	return A(pos[c] - pos[d]) <= ld;
}

void possible(int c, int d, int ld){ // d : 1 > , -1 <
	if (c == n + 1 && d == 1){
		possible(c, -d, ld);
	}
	else if (c == 0 && d == -1){
		good = true;
	}
	else if (cango(c, c + d, ld)){
		if (!type[c + d]){
			if(!good)possible(c + d, d, ld);
		}
		else{
			int nxt = c + 2 * d;
			if (0 <= nxt && nxt <= n + 1 && cango(c, nxt, ld)){
				if (type[nxt] == 1){
					if (!chk[nxt]){
						chk[nxt] = true;
						if (!good)possible(nxt, d, ld);
						chk[nxt] = false;
					}
				}
				else{
					if (!good)possible(nxt, d, ld);
				}
			}
			nxt = c + d;
			if (!chk[nxt]){
				chk[nxt] = true;
				if (!good)possible(nxt, d, ld);
				chk[nxt] = false;
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int d;
		scanf("%d %d", &n, &d);

		int ans = INT_MAX;

		pos[0] = 0, pos[n + 1] = d;

		for (int i = 1; i <= n; i++){
			char x;
			int y;
			scanf(" %c-%d", &x, &pos[i]);
			if (x == 'W'){ // wood
				type[i] = 0;
			}
			else if (x == 'T'){ // flying turtle
				type[i] = 1;
			}
		}

		int l = 1, r = d, ld;
		while (l <= r){
			ld = (l + r) / 2;

			memset(chk, 0, sizeof(chk));

			good = false;
			possible(0, 1, ld);
			if (good){
				r = ld - 1;
				ans = m(ans, ld);
			}
			else{
				l = ld + 1;
			}

		}

		printf("%d\n", ans);
	}
}