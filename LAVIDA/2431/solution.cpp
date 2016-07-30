#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

vector < vector < int > > L;
vector < vector < int > > V;
vector <int> dat;

int d[22];
int n, m, k;
int ans;
bool chk[22][22];

void Func(int c){ // O(n^2 * C) C = 10000
	int x = dat[c];
	d[x] = 0;
	for (int i = 0; i < c; i++){
		int j = dat[i];
		if (chk[j][x]){
			d[x] += d[j];
		}
	}
	if (V[x].size()){
		for (int i = 0; i < V[x].size(); i++){
			d[x] += V[x][i];
			if (c == n-1){
				if (d[n] >= k)ans++; // dat[n-1] != n ==> must be included cases
				d[x] -= V[x][i];
				continue;
			}
			Func(c + 1);
			d[x] -= V[x][i];
		}
	}
	else{
		if (c == n-1){
			if (d[n] >= k)ans++;
			return;
		}
		Func(c + 1);
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d %d", &n, &m, &k);

		int in[22] = { 0 };
		memset(chk, 0, sizeof(chk));

		L.resize(n + 1), V.resize(n + 1);

		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			in[b]++;
			chk[a][b] = true;
			L[a].push_back(b);
		}

		queue <int> net;
		for (int i = 1; i <= n; i++){
			if (!in[i]){
				net.push(i);
				dat.push_back(i);
			}
		}
		while (!net.empty()){
			int f = net.front(); net.pop();
			for (int i = 0; i < L[f].size(); i++){
				in[L[f][i]]--;
				if (!in[L[f][i]]){
					net.push(L[f][i]);
					dat.push_back(L[f][i]);
				}
			}
		}

		int s;
		scanf("%d", &s);
		for (int i = 1; i <= s; i++){
			int a, c;
			scanf("%d %d", &a, &c);
			for (int i = 1; i <= c; i++){
				int v;
				scanf("%d", &v);
				V[a].push_back(v);
			}
		}

		memset(d, 0, sizeof(d));

		ans = 0;
		Func(0);

		printf("%d\n", ans);
		
		dat.clear();
		for (int i = 1; i <= n; i++)L[i].clear(), V[i].clear();
	}
}