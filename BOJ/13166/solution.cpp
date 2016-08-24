#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

struct HopcroftKarp // E * sqrt (V)
{

	int n, m;
	vector<vector<int>> graph;
	vector<int> match, matched, depth, q, v;
	int vcnt;

	void init(int n_, int m_){
		n = n_, m = m_;
		graph.resize(n), match.resize(n), matched.resize(m), depth.resize(n), q.resize(n), v.resize(n);
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}

	bool BFS(){
		int t = 0;
		for (int i = 0; i < n; i++)
			if (match[i] == -1) depth[i] = 0, q[t++] = i;
			else depth[i] = -1;
		for (int h = 0; h < t; h++) {
			int cur = q[h];
			int curDepth = depth[cur];
			for (int i = 0; i < graph[cur].size(); i++) {
				int adj = graph[cur][i];
				if (matched[adj] == -1)
					return true;
				int next = matched[adj];
				if (depth[next] != -1) continue;
				depth[next] = curDepth + 1, q[t++] = next;
			}
		}
		return false;
	}

	bool DFS(int nod) {
		v[nod] = vcnt;
		for (int i = 0; i < graph[nod].size(); i++) {
			int adj = graph[nod][i];
			int next = matched[adj];
			if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
				continue;
			if (next == -1 || DFS(next)) {
				match[nod] = adj;
				matched[adj] = nod;
				return true;
			}
		}
		return false;
	}

	int Match()
	{
		fill(match.begin(), match.end(), -1);
		fill(matched.begin(), matched.end(), -1);
		int ans = 0;
		while (BFS()) {
			++vcnt;
			for (int i = 0; i < n; i++) if (depth[i] == 0 && DFS(i)) ans++;
		}
		return ans;
	}
};

class ele{
public:

	int i, j, c;
	ele(){}
	ele(int _i, int _j, int _c){
		i = _i, j = _j, c = _c;
	}

	bool operator<(const ele &A)const{
		return c < A.c;
	}

};

int main(){

	int n;
	scanf("%d", &n);

	vector < ele > v(n<<1);

	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			int x, y;
			scanf("%d %d", &x, &y);

			v[(i<<1)|j] = {i, x-1, y};
		}
	}

	sort(v.begin(), v.end());

	int l = 0, r = 1000003, m;

	int ans = r;

	while(l <= r){

		m = (l+r) / 2;

		HopcroftKarp btm;
		btm.init(n, (n<<1));

		for(int i=0; i<(n<<1); i++){
			if(v[i].c <= m){
				btm.add_edge(v[i].i, v[i].j);
			}else{
				break;
			}
		}

		if(btm.Match() == n){
			r = m - 1;
			ans = min(ans, m);
		}else{
			l = m + 1;
		}
	}

	if(ans == 1000003)ans = -1;

	printf("%d\n", ans);

}
