//#include <stdio.h>
//#include <memory.h>
//#include <limits.h>
//
//#include <vector>
//#include <map>
//
//#define min(a, b) (a<b?a:b)
//#define max(a, b) (a<b?b:a)
//
//using namespace std;
//
//#define node 203
//
//class AnotherMaxFlow{
//public:
//	struct edge { int to, cap, rev; };
//	vector<edge> G[node];
//	bool used[node];
//
//	void add_edge(int from, int to, int cap) {
//		edge e;
//		e.to = to, e.cap = cap, e.rev = G[to].size();
//		G[from].push_back(e);
//		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
//		G[to].push_back(e);
//	}
//
//	int dfs(int v, int t, int f) {
//		if (v == t)return f;
//		used[v] = 1;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge &e = G[v][i];
//			if (!used[e.to] && e.cap > 0) {
//				int d = dfs(e.to, t, min(f, e.cap));
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
//	int max_flow(int s, int t) {
//		int flow = 0;
//		while (1) {
//			memset(used, 0, sizeof used);
//			int f = dfs(s, t, 987654321);
//			if (f == 0)return flow;
//			flow += f;
//		}
//		return flow;
//	}
//};
//
//char str[55][55];
//
//int main(){
//	int n, k;
//	scanf("%d %d", &n, &k);
//
//	AnotherMaxFlow mf;
//	for (int i = 1; i <= n; i++){
//		scanf("%s", str[i] + 1);
//
//		mf.add_edge(0, i, n); // link to source
//		mf.add_edge(2 * n + i, 4 * n + 1, n); // link to sink
//
//		mf.add_edge(i, n + i, k); // at best k
//		mf.add_edge(3 * n + i, 2 * n + i, k); // at best k
//
//		for (int j = 1; j <= n; j++){
//			if (str[i][j] == '1')mf.add_edge(i, 2 * n + j, 1); // love
//			else{ // hate
//				mf.add_edge(n + i, 3 * n + j, 1);
//			}
//		}
//	}
//
//	int ans = INT_MAX;
//	mf.max_flow(0, 4 * n + 1);
//	for (int i = 0; i < mf.G[4 * n + 1].size(); i++){
//		int cmp = mf.G[4 * n + 1][i].cap;
//		ans = min(ans, cmp);
//	}
//	printf("%d\n", ans);
//}
//
///*			n+i 3n+i
//	0	i				2n+i 4n+1
//*/

#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <vector>
#include <map>

#define min(a, b) (a<b?a:b)
#define max(a, b) (a<b?b:a)

using namespace std;

#define node 203

class AnotherMaxFlow{
public:
	struct edge { int to, cap, rev; };
	vector<edge> G[node];
	bool used[node];

	void add_edge(int from, int to, int cap) {
		edge e;
		e.to = to, e.cap = cap, e.rev = G[to].size();
		G[from].push_back(e);
		e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
		G[to].push_back(e);
	}

	int dfs(int v, int t, int f) {
		if (v == t)return f;
		used[v] = 1;
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		while (1) {
			memset(used, 0, sizeof used);
			int f = dfs(s, t, 987654321);
			if (f == 0)return flow;
			flow += f;
		}
		return flow;
	}
};

char str[55][55];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	AnotherMaxFlow mf;
	for (int i = 1; i <= n; i++){
		scanf("%s", str[i] + 1);

		mf.add_edge(i, n + i, k); // at best k
		mf.add_edge(3 * n + i, 2 * n + i, k); // at best k

		for (int j = 1; j <= n; j++){
			if (str[i][j] == '1')mf.add_edge(i, 2 * n + j, 1); // love
			else{ // hate
				mf.add_edge(n + i, 3 * n + j, 1);
			}
		}
	}

	int max = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			mf.add_edge(0, j, 1); // link to source
			mf.add_edge(2 * n + j, 4 * n + 1, 1); // link to sink
		}

		int cmp = mf.max_flow(0, 4 * n + 1);

		if (cmp == n){
			max = i;
		}
		else{
			break;
		}
	}

	printf("%d\n", max);
}

/*		n+i 3n+i
0	i			2n+i 4n+1
*/