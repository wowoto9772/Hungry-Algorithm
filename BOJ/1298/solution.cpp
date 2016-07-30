#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <queue>
#include <vector>

using namespace std;

int cap[205][205], flow[205][205];
int P[205];

int m(int a, int b){ return a < b ? a : b; }

int MaximumFlow(int source, int sink){ // fordFulkerson

	int ret = 0;

	memset(flow, 0, sizeof(flow));

	while (true){

		queue <int> Q;

		memset(P, 0xff, sizeof(P));
		P[source] = source; // argument path
		Q.push(source);

		while (!Q.empty() && P[sink] == -1){
			int now = Q.front(); Q.pop();

			for (int nxt = 0; nxt <= 201; nxt++){
				if (cap[now][nxt] - flow[now][nxt] > 0 && P[nxt] == -1){
					// amount to use
					Q.push(nxt);
					P[nxt] = now;
				}
			}
		}

		if (P[sink] == -1)break; // end condition

		int amount = INT_MAX;

		for (int p = sink; p != source; p = P[p]){
			amount = m(amount, cap[P[p]][p] - flow[P[p]][p]);
		}

		for (int p = sink; p != source; p = P[p]){
			flow[P[p]][p] += amount;
			flow[p][P[p]] -= amount;
		}

		ret += amount;
	}

	return ret;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		cap[a][n + b] = 1; // make graph data
		cap[0][a] = 1; // linked with source
		cap[n + b][201] = 1; // linked with sink
	}

	printf("%d\n", MaximumFlow(0, 201));
}

/*
	4 2
	....
	X...
	...X
	.X..
*/