#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <queue>

using namespace std;

int cap[153][153];
int flow[153][153];

int P[153];
int min(int a, int b){
	return a < b ? a : b;
}

int fordFulkerson(int source, int sink){
	int ret = 0;

	memset(flow, 0, sizeof(flow));

	while (true){

		queue <int> Q;

		memset(P, 0xff, sizeof(P));
		P[source] = source; // argument path
		Q.push(source);

		while (!Q.empty() && P[sink] == -1){
			int now = Q.front(); Q.pop();

			for (int nxt = source; nxt <= sink; nxt++){
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
			amount = min(amount, cap[P[p]][p] - flow[P[p]][p]);
		}

		for (int p = sink; p != source; p = P[p]){
			flow[P[p]][p] += amount;
			flow[p][P[p]] -= amount;
		}

		ret += amount;
	}

	return ret;
}


int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int m, f;
		scanf("%d %d", &m, &f);

		memset(cap, 0, sizeof(cap));

		vector < vector <int> > lnk;
		lnk.resize(f + 1);

		for (int i = 1; i <= f; i++){
			int c;
			scanf("%d", &c);
			for (int j = 1; j <= c; j++){
				int a;
				scanf("%d", &a);
				a++;
				lnk[i].push_back(f + a);
			}
		}

		long long l = 1, r = 101, mid;
		int ans = 101;

		while (l <= r){
			mid = (l + r) / 2;
			for (int i = 1; i <= f; i++){
				cap[0][i] = mid;
				for (int j = 0; j < lnk[i].size(); j++){
					cap[i][lnk[i][j]] = mid;
				}
			}

			for (int i = f + 1; i <= m + f; i++)cap[i][m + f + 1] = 1;

			int c = fordFulkerson(0, m + f + 1);
			if (c == m){
				ans = min(ans, mid);
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}

		if (ans == 101)printf("impossible\n");
		else
			printf("%d\n", ans);
	}
}