#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

struct HopcroftKarp // E * sqrt ( V )
{

	int n, m;
	vector<vector<int>> graph;
	vector<int> match, matched, depth, q, v;
	int vcnt;

	void Init(int n_, int m_){
		n = n_, m = m_;
		graph.resize(n), match.resize(n), matched.resize(m), depth.resize(n), q.resize(n), v.resize(n);
	}


	void AddEdge(int u, int v) {
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

#define ll long long

ll x[2503], y[2503];

int main(){

	int n;
	scanf("%d", &n);

	HopcroftKarp btm;
	
	btm.Init(n+1, 3*n+1);

	int top = 0;

	map < ll, int > v;
	map < int, ll > dv;
	
	for(int i=1; i<=n; i++){

		ll a, b;
		scanf("%lld %lld", &a, &b);

		x[i] = a, y[i] = b;

		ll c[] = {a-b, a+b, a*b};

		for(int j=0; j<3; j++){

			if(!v[c[j]]){
				v[c[j]] = ++top;
				dv[top] = c[j];
			}

			int e = v[c[j]];

			btm.AddEdge(i, e);

		}

	}

	char c[] = "-+*";

	if(btm.Match() == n){

		for(int i=1; i<=n; i++){

			ll a = x[i], b = y[i];

			ll c = dv[btm.match[i]];

			if(a+b == c)printf("%lld + %lld = %lld\n", a, b, a+b);
			else if(a-b == c)printf("%lld - %lld = %lld\n", a, b, a-b);
			else
				printf("%lld * %lld = %lld\n", a, b, a*b);

		}
	}else{
		printf("impossible\n");
	}

}
