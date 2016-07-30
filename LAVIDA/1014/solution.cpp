#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <queue>

using namespace std;

int cap[203][203], flow[203][203], P[203]; // n * n * 2

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

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int s;
		scanf("%d", &s);

		bool chk[13][13] = { 0 };
		int grp[2][13][13] = { 0 };
		for (int i = 1; i <= s; i++){
			char str[13] = { 0 };
			scanf("%s", str+1);
			for (int j = 1; j <= s; j++){
				if (str[j] == '*')chk[i][j] = true;
			}
		}

		// make graph
		int idn = 0;
		for (int i = 1; i <= s; i++){
			for (int j = 1; j <= s; j++){

				int x = i, y = j;
				int dx = 1, dy = -1; // left bot

				bool flag = false;
				if (!grp[1][x][y]){
					while (x >= 1 && x <= s && y >= 1 && y <= s){
						if (chk[x][y]){
							break;
						}
						else{
							if (!flag){
								idn++;
								flag = true;
							}
							grp[1][x][y] = idn;
						}
						x += dx, y += dy;
					}
				}

				x = i, y = j;
				dy = 1; // right bot

				if (!grp[0][x][y]){
					flag = false;
					while (x >= 1 && x <= s && y >= 1 && y <= s){
						if (chk[x][y]){
							break;
						}
						else{
							if (!flag){
								idn++;
								flag = true;
							}
							grp[0][x][y] = idn;
						}
						x += dx, y += dy;
					}
				}
			}
		}

		idn++;
		memset(cap, 0, sizeof(cap));
		for (int i = 1; i <= s; i++){
			for (int j = 1; j <= s; j++){
				if (grp[0][i][j] && grp[1][i][j]){
					cap[0][grp[0][i][j]] = 1;
					cap[grp[0][i][j]][grp[1][i][j]] = 1;
					cap[grp[1][i][j]][idn] = 1;
				}
			}
		}

		printf("%d\n", MaximumFlow(0, idn));
	}
}