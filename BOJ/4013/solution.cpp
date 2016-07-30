#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class ele{
public:
	int a, c;
};

vector < vector <int> > F, R, X, GF;

int n, m, top;
int M[500003]; // point cst
bool E[500003]; // end point

bool v[500003];
int stk[500003]; // for finding cycle

int G[500003]; // group id
int C[500003]; // group cst
int g; // group cnt
bool GE[500003]; // group end point
int d[500003]; // maximum dijkstra
int e[500003]; // ending point;

void DFN(int a){
	v[a] = true;
	for (int i = 0; i < F[a].size(); i++){
		if (v[F[a][i]])continue;
		DFN(F[a][i]);
	}
	stk[top++] = a;
}

void CYC(int a){
	G[a] = g;
	C[g] += M[a];
	if (E[a])GE[g] = true;
	X[g].push_back(a); // g's member is a
	for (int i = 0; i < R[a].size(); i++){
		if (!G[R[a][i]]){
			CYC(R[a][i]);
		}
	}
}

int dp[500003];
int Max(int a, int b){ return a < b ? b : a; }
int dy(int c){
	if (dp[c] != -1)return dp[c];
	dp[c] = 0;

	for (int i = 0; i < GF[c].size(); i++){
		dp[c] = Max(dp[c], C[c] + dy(GF[c][i]));
	}

	if (c != g && !dp[c])dp[c] = -INT_MAX;

	return dp[c];
}


int main()
{
	scanf("%d %d", &n, &m);

	F.resize(n + 1), R.resize(n + 1), X.resize(n + 1);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		F[a].push_back(b); // forward
		R[b].push_back(a); // backward
	}

	top = 0;
	for (int i = 1; i <= n; i++){
		if (!v[i])DFN(i);
	}

	for (int i = 1; i <= n; i++)scanf("%d", &M[i]);

	int s, r;
	scanf("%d %d", &s, &r);
 
	for (int i = 1; i <= r; i++){
		scanf("%d", &e[i]);
		E[e[i]] = true; // end point
	}

	g = 0;
	for (int i = top - 1; i >= 0; i--){
		if (!G[stk[i]]){
			g++;
			C[g] = 0;
			GE[g] = false;
			CYC(stk[i]);
		}
	}

	map <int, map<int, bool> > chk;
	GF.resize(n + 1);

	for (int i = 1; i <= g; i++){
		for (int j = 0; j < X[i].size(); j++){
			int now = X[i][j];
			for (int k = 0; k < F[now].size(); k++){
				int nxt = G[F[now][k]];
				if (i != nxt && !chk[i][nxt]){
					GF[i].push_back(nxt);
					chk[i][nxt] = true;
				}
			}
		}
	}

	g++;
	for (int i = 1; i <= r; i++){
		if (chk[G[e[i]]][g])continue;
		GF[G[e[i]]].push_back(g);
		chk[G[e[i]]][g] = true;
	}

	memset(dp, 0xff, sizeof(dp));
	printf("%d\n", dy(G[s]));
}