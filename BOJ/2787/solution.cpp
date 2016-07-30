//#include <stdio.h>
//#include <memory.h>
//
//#include <vector>
//#include <map>
//
//#define min(a, b) (a<b?a:b)
//
//using namespace std;
//
//#define node 603
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
//bool used[202];
//int ans[202];
//
//int main(){
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	AnotherMaxFlow mf;
//
//	for (int i = 1; i <= m; i++){
//		int f, x, y, v;
//		scanf("%d %d %d %d", &f, &x, &y, &v);
//
//		if (x > y){
//			int t = x;
//			x = y;
//			y = t;
//		}
//
//		used[v] = true;
//
//		for (int j = x; j <= y; j++){
//			mf.add_edge(j, n + v, 1);
//		}
//	}
//
//	for (int i = 1; i <= n; i++){
//		mf.add_edge(0, i, 1);
//		mf.add_edge(n + i, 2 * n + 1, 1);
//		if (used[i])continue;
//		for (int j = 1; j <= n; j++){
//			mf.add_edge(j, n + i, 1);
//		}
//	}
//
//	int cmp = mf.max_flow(0, 2 * n + 1);
//
//	if (cmp == n){
//		for (int i = 1; i <= n; i++){
//			for (int j = 0; j < mf.G[i].size(); j++){
//				if (mf.G[i][j].to > n && !mf.G[i][j].cap){
//					ans[i] = mf.G[i][j].to - n;
//					break;
//				}
//			}
//		}
//
//		for (int i = 1; i < n; i++)printf("%d ", ans[i]);
//		printf("%d\n", ans[n]);
//	}
//	else{
//		printf("-1\n");
//	}
//}
//
///*		position	value
//	0	i			n+i		2*n+1
//*/

//#include <stdio.h>
//#include <memory.h>
//
//#include <vector>
//#include <map>
//
//#define min(a, b) (a<b?a:b)
//#define max(a, b) (a<b?b:a)
//
//using namespace std;
//
//#define node 603
//
//class AnotherMaxFlow{
//public:
//	struct edge { int to, cap, rev; };
//	vector<edge> G[node];
//	bool used[node];
//
//	void add_edge(int from_, int to_, int cap_) {
//		edge e;
//		e.to = to_, e.cap = cap_, e.rev = G[to_].size();
//		G[from_].push_back(e);
//		e.to = from_, e.cap = 0, e.rev = G[from_].size() - 1;
//		G[to_].push_back(e);
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
//bool used[202][3];
//int ans[202];
//int mx[202][2], Mx[202][2];
//
//int main(){
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	AnotherMaxFlow mf;
//
//	bool flag = false;
//
//	for (int i = 1; i <= m; i++){
//		int f, x, y, v;
//		scanf("%d %d %d %d", &f, &x, &y, &v);
//
//		if (flag)continue;
//
//		if (x > y){
//			int t = x;
//			x = y;
//			y = t;
//		}
//
//		if (!used[v][f]){
//			used[v][f] = true;
//			if (f == 2){
//				mx[v][0] = x, mx[v][1] = y;
//			}
//			else{
//				Mx[v][0] = x, Mx[v][1] = y;
//			}
//		}
//		else{
//			if (f == 2){
//				if (mx[v][1] < x || y < mx[v][0]){
//					flag = true;
//				}
//				else{
//					if (mx[v][0] < x)mx[v][0] = x;
//					if (mx[v][1] > y)mx[v][1] = y;
//				}
//			}
//			else{
//				if (Mx[v][1] < x || y < Mx[v][0]){
//					flag = true;
//				}
//				else{
//					if (Mx[v][0] < x)Mx[v][0] = x;
//					if (Mx[v][1] > y)Mx[v][1] = y;
//				}
//			}
//		}
//	}
//
//	bool assn[202] = { 0 };
//
//	for (int i = 1; !flag && i <= n; i++){
//		if (used[i][1] || used[i][2]){
//			if (used[i][1] && used[i][2]){
//				int l = max(mx[i][0], Mx[i][0]);
//				int r = min(mx[i][1], Mx[i][1]);
//				if (l > r)flag = true;
//			}
//			if (used[i][2]){
//				for (int j = i - 1; j >= 1; j--){
//					if (!used[j][2])continue;
//					int l = max(mx[j][0], mx[i][0]);
//					int r = min(mx[j][1], mx[i][1]);
//					if (l <= r){
//						flag = true;
//					}
//				}
//				for (int j = mx[i][0]; j <= mx[i][1]; j++){
//					assn[j] = true;
//					for (int k = i; k <= n; k++){
//						mf.add_edge(j, n + k, 1);
//					}
//				}
//			}
//			if(used[i][1]){
//				for (int j = i + 1; j <= n; j++){
//					if (!used[j][1])continue;
//					int l = max(Mx[j][0], Mx[i][0]);
//					int r = min(Mx[j][1], Mx[i][1]);
//					if (l <= r){
//						flag = true;
//					}
//				}
//				for (int j = Mx[i][0]; j <= Mx[i][1]; j++){
//					assn[j] = true;
//					for (int k = 1; k <= i; k++){
//						mf.add_edge(j, n + k, 1);
//					}
//				}
//			}
//		}
//	}
//
//	if (flag)printf("-1\n");
//	else{
//		for (int i = 1; i <= n; i++){
//			mf.add_edge(0, i, 1); // link to source(position)
//			mf.add_edge(n + i, 2 * n + 1, 1); // link to sink(number)
//
//			if (used[i][1] || used[i][2])continue;
//			for (int j = 1; j <= n; j++){
//				if (assn[j])continue;
//				mf.add_edge(j, n + i, 1);
//			}
//		}
//
//		int cmp = mf.max_flow(0, 2 * n + 1);
//
//		if (cmp == n){
//			for (int i = n + 1; i <= 2 * n; i++){
//				for (int j = 0; j < mf.G[i].size(); j++){
//					if (mf.G[i][j].to <= n && mf.G[i][j].cap == 1){
//						ans[mf.G[i][j].to] = i - n;
//						break;
//					}
//				}
//			}
//			for (int i = 1; i < n; i++)printf("%d ", ans[i]);
//			printf("%d\n", ans[n]);
//		}
//		else{
//			printf("-1\n");
//		}
//	}
//}

/*		position	value
0	i			n+i		2*n+1
*/

/*
3 2
1 1 2 1
1 2 3 1

3 3
1 1 2 1
1 2 3 1
2 3 3 1

4 2
2 1 2 2
1 3 3 4
2 3 4 1
*/

#include <stdio.h>
#include <memory.h>

#include <vector>
#include <map>

#define min(a, b) (a<b?a:b)
#define max(a, b) (a<b?b:a)

using namespace std;

#define node 603

class AnotherMaxFlow{
public:
	struct edge { int to, cap, rev; };
	vector<edge> G[node];
	bool used[node];

	void add_edge(int from_, int to_, int cap_) {
		edge e;
		e.to = to_, e.cap = cap_, e.rev = G[to_].size();
		G[from_].push_back(e);
		e.to = from_, e.cap = 0, e.rev = G[from_].size() - 1;
		G[to_].push_back(e);
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

bool used[202][3];
int ans[202];
int mx[202][2], Mx[202][2];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	AnotherMaxFlow mf;

	int pos[202][2], val[202][2]; // position, value

	for (int i = 1; i <= n; i++){
		pos[i][1] = val[i][1] = n;
		pos[i][0] = val[i][0] = 0;
	}

	for (int i = 1; i <= m; i++){
		int f, x, y, v;
		scanf("%d %d %d %d", &f, &x, &y, &v);

		if (x > y){
			int t = x;
			x = y;
			y = t;
		}

		pos[v][0] = max(pos[v][0], x);
		pos[v][1] = min(pos[v][1], y);

		for (int j = x; j <= y; j++){
			if (f == 2){ // min
				val[j][0] = max(val[j][0], v);
			}
			else{ // max
				val[j][1] = min(val[j][1], v);
			}
		}
	}



	for (int i = 1; i <= n; i++){
		mf.add_edge(0, i, 1); // link to source(position)
		mf.add_edge(n + i, 2 * n + 1, 1); // link to sink(number)
		for (int j = pos[i][0]; j <= pos[i][1]; j++){
			if (val[j][0] <= i && i <= val[j][1]){
				mf.add_edge(j, n + i, 1);
			}
		}
	}

	int cmp = mf.max_flow(0, 2 * n + 1);

	if (cmp == n){
		for (int i = n + 1; i <= 2 * n; i++){
			for (int j = 0; j < mf.G[i].size(); j++){
				if (mf.G[i][j].to <= n && mf.G[i][j].cap == 1){
					ans[mf.G[i][j].to] = i - n;
					break;
				}
			}
		}
		for (int i = 1; i < n; i++)printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	else{
		printf("-1\n");
	}
}