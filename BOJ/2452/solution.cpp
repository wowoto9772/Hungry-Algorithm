#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class ele{
public:
	int r, c;
	ele(){}
	ele(int a, int b){ r = a, c = b; }
};

bool chk[10001][10001];

int I[103][103];
int grp[103][103];

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			scanf("%d", &I[i][j]);;
			grp[i][j] = -1;
		}
	}

	int top = 0;

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			if (grp[i][j] == -1){
				grp[i][j] = ++top;

				queue <ele> q;
				q.emplace(i, j);

				while (!q.empty()){

					ele f = q.front(); q.pop();

					for (int k = 0; k < 4; k++){

						ele g{ f.r + dr[k], f.c + dc[k] };
						if (g.r < 1 || g.c < 1 || g.r > r || g.c > c)continue;

						if (grp[g.r][g.c] == -1 && I[g.r][g.c] == I[i][j]){

							grp[g.r][g.c] = top;
							q.emplace(g.r, g.c);

						}

					}

				}
			}
		}
	}

	vector < vector <int> > lnk;
	lnk.resize(top + 1);

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			for (int k = 0; k < 4; k++){
				int ni = i + dr[k];
				int nj = j + dc[k];
				int cur = grp[i][j];
				int nxt = grp[ni][nj];
				if (nxt){
					if (!chk[cur][nxt]){
						chk[cur][nxt] = chk[nxt][cur] = true;

						lnk[cur].push_back(nxt);
						lnk[nxt].push_back(cur);
					}
				}
			}
		}
	}

	vector < bool > ahead;
	ahead.resize(top + 1, true);

	vector <int> k;
	for (int i = top / 2; i <= 2*top/3; i++)k.push_back(i);
	for (int i = top / 2 - 1; i >= top/3; i--)k.push_back(i);
	for (int i = 2 * top / 3 + 1; i <= top; i++)k.push_back(i);
	for (int i = top / 3 - 1; i >= 1; i--)k.push_back(i);

	int ans = INT_MAX;

	vector <int> vst;
	vst.resize(top + 1, -1);

	for (int a = 0; a < k.size(); a++){

		int i = k[a];

		if (ahead[i]){

			int tmp = 0;

			vector <int> x;

			queue <int> q, t;
			q.push(i);
			t.push(0);
			vst[i] = a;

			while (!q.empty()){

				int f = q.front(); q.pop();
				int m = t.front(); t.pop();

				++m;
				if (m > ans)break;

				for (int j = 0; j < lnk[f].size(); j++){

					if (vst[lnk[f][j]] != a){
						vst[lnk[f][j]] = a;
						q.push(lnk[f][j]);
						t.push(m);

						if (tmp < m){
							tmp = m;
							x.clear();
							x.push_back(lnk[f][j]);
						}
						else if (tmp == m){
							x.push_back(lnk[f][j]);
						}
					}

				}

			}

			for (int j = 0; j < x.size(); j++)ahead[x[j]] = false;

			ans = min(ans, tmp);

		}

	}


	printf("%d\n", ans);
}