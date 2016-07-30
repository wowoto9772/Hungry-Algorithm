#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int src[52], snk[52];
int cap[2604][2604];
int flow[2604][2604];
int P[2604];
vector < int > link[2604];

int m(int a, int b){ return a < b ? a : b; }

int MaximumFlow(int source, int sink){ // fordFulkerson

	int ret = 0;

	while (true){

		queue <int> Q;

		memset(P, 0xff, sizeof(P));
		P[source] = source; // argument path
		Q.push(source);

		while (!Q.empty() && P[sink] == -1){
			int now = Q.front(); Q.pop();

			for (int i = 0; i < link[now].size(); i++){
				int nxt = link[now][i];
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
	int n;
	scanf("%d", &n);

	int l = 0, r = 0;

	int goal = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &snk[i]);
		goal += snk[i];
		r = r < snk[i] ? snk[i] : r;
	}
	for (int i = 1; i <= n; i++)scanf("%d", &src[i]);

	int limit;

	bool flag = false;

	int ans = INT_MAX;
	int ans2[52][52];

	while (l <= r){
		limit = (l + r) / 2;

		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));

		for (int i = 1; i <= n; i++){
			cap[0][i] = src[i];
			cap[n*n + n + i][n*n + 2 * n + 1] = snk[i];
			for (int j = 1; j <= n; j++){
				int x = n + n * (i - 1) + j;
				cap[j][x] = limit;
				cap[x][n*n + n + i] = limit;
				if (!flag){
					link[x].push_back(n*n + n + i); // forward
					link[n*n + n + i].push_back(x); // backward
					link[j].push_back(x); // forward
					link[x].push_back(j); // backward
				}
			}
			if (!flag){
				link[0].push_back(i); // forward
				link[n*n + n + i].push_back(n*n + 2 * n + 1); // forward
			}
		}

		int cmp = MaximumFlow(0, n*n + 2 * n + 1);
		if (cmp >= goal){
			r = limit - 1;
			if (ans > limit){
				ans = limit;
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						int x = n + n * (i - 1) + j;
						ans2[i][j] = flow[j][x];
					}
				}
			}
		}
		else if (cmp < goal){
			l = limit + 1;
		}

		flag = true;
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < n; j++)printf("%d ", ans2[i][j]);
		printf("%d\n", ans2[i][n]);
	}
}