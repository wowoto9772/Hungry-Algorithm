#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <queue>

using namespace std;

int p[204];
int cap[204][204];
int flow[204][204];

int min(int a, int b){ return a < b ? a : b; }
int abs(int a){ return a < -a ? -a : a; }

int maximum_flow(int s, int e){
	memset(flow, 0, sizeof(flow));

	int ret = 0;
	while (true){
		memset(p, 0xff, sizeof(p));
		queue <int> q;
		q.push(s);
		p[s] = 0;

		while (!q.empty() && p[e] == -1){
			int c = q.front(); q.pop();
			for (int i = 1; i <= e; i++){
				if (cap[c][i] - flow[c][i] > 0 && p[i] == -1){
					p[i] = c;
					q.push(i);
				}
			}
		}

		if (p[e] == -1)return ret;

		int f = e;
		int cf = INT_MAX;
		while (p[f] > 0){
			cf = min(cf, cap[p[f]][f] - flow[p[f]][f]);
			f = p[f];
		}

		f = e;
		while (p[f] > 0){
			flow[p[f]][f] += cf;
			flow[f][p[f]] -= cf;
			f = p[f];
		}

		ret += cf;
	}
}

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) == 2){
		memset(cap, 0, sizeof(cap));
		for (int i = 1; i <= m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			cap[a][b] += c; // there are same edges.
		}

		printf("%d\n", maximum_flow(1, n));
	}
}
