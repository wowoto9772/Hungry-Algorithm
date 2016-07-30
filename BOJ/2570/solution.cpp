#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <vector>
#include <map>
#include <queue>

using namespace std;

int P[20003];
vector < vector <int> > L;
map <int, map <int, int> > cap, flow;

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

			for (int i = 0; i < L[now].size(); i++){
				int nxt = L[now][i];
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
	int s;
	scanf("%d", &s);

	int n;
	scanf("%d", &n);

	bool chk[103][103] = { 0 };
	int grp[2][103][103] = { 0 };
	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		chk[a][b] = true;
	}

	// make graph
	int idn = 0;
	for (int i = 1; i <= s; i++){
		for (int j = 1; j <= s; j++){

			int x = i, y = j;
			int dx = -1, dy = 1; // left bot

			bool flag = false;
			if (!grp[1][x][y]){
				while (x >= 1 && y <= s){
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
			dx = 1; // right bot

			if (!grp[0][x][y]){
				flag = false;
				while (x <= s && y <= s){
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
	L.resize(idn + 1);
	for (int i = 1; i <= s; i++){
		for (int j = 1; j <= s; j++){
			if (grp[0][i][j] && grp[1][i][j]){
				cap[0][grp[0][i][j]] = 1;
				flow[0][grp[0][i][j]] = 0;
				L[0].push_back(grp[0][i][j]);

				cap[grp[0][i][j]][grp[1][i][j]] = 1;
				flow[grp[0][i][j]][grp[1][i][j]] = 0;
				L[grp[0][i][j]].push_back(grp[1][i][j]); // forward
				flow[grp[1][i][j]][grp[0][i][j]] = 0;
				L[grp[1][i][j]].push_back(grp[0][i][j]); // backward

				cap[grp[1][i][j]][idn] = 1;
				flow[grp[1][i][j]][idn] = 0;
				L[grp[1][i][j]].push_back(idn);
			}
		}
	}

	printf("%d\n", MaximumFlow(0, idn));
}