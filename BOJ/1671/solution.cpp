#include <stdio.h>
#include <memory.h>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <math.h>

using namespace std;

class ele{
public:
	int sz, sp, it;
	bool operator<(const ele &A)const{
		if (sz == A.sz){
			if (sp == A.sp)return it > A.it;
			return sp > A.sp;
		}
		return sz > A.sz;
	}
}X[53];

int cap[103][103];
int flow[103][103];
int prv[103];

int fordFulkerson(int n, int s, int t){
	int m_flow = 0; // maximum flow

	while (true){
		memset(prv, 0xff, sizeof(prv));

		queue <int> q;
		prv[s] = -2;
		q.push(s);

		while (!q.empty() && prv[t] == -1){
			int u = q.front();
			q.pop();

			for (int v = 1; v <= 2 * n + 1; v++){
				if (prv[v] == -1){ // not seen yet
					if (flow[v][u] || flow[u][v] < cap[u][v]){
						prv[v] = u; // v's prvious node is u
						q.push(v);
					}
				}
			}
		}

		if (prv[t] == -1)break; // couldn't find any path to t(sink)

		int bot = INT_MAX;
		for (int v = t, u = prv[v]; u >= 0; v = u, u = prv[v]){
			if (flow[v][u]) // always use backward edge over forward
				bot = min(bot, flow[v][u]);
			else // must be a forwad edge otherwise
				bot = min(bot, cap[u][v] - flow[u][v]);
		}

		for (int v = t, u = prv[v]; u >= 0; v = u, u = prv[v]){
			if (flow[v][u]) // backward edge
				flow[v][u] -= bot;
			else // forward edge
				flow[u][v] += bot;
		}

		m_flow += bot;
	}
	return m_flow;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d %d %d", &X[i].sz, &X[i].sp, &X[i].it);
	}

	memset(flow, 0, sizeof(flow));
	memset(cap, 0, sizeof(cap));

	sort(X + 1, X + 1 + n);
	// Make graph
	for (int i = 1; i <= n; i++){
		cap[0][i] = 2; // linked with source
		for (int j = i + 1; j <= n; j++){
			if (X[i].sp >= X[j].sp){
				if (X[i].it >= X[j].it){
					cap[i][n + j] = 1; // linked edge
				}
			}
		}
		cap[n + i][2 * n + 1] = 1; // linked with sink
	}

	printf("%d\n", n - fordFulkerson(n, 0, 2 * n + 1));

}